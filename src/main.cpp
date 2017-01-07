#include "parse.hpp"
#include <iostream>

using namespace std;

int main(int argc, char * argv[]){

	auto& materials = ResourceManager<Material>::getInstance();
	auto& shapes = ResourceManager<IShape>::getInstance();
	auto& objects = ResourceManager<Object>::getInstance();
	auto& lamps = ResourceManager<Lamp>::getInstance();

	Scene scene;
	LampSet lSet;

	auto addObject = [&](IShape* shape, Material* material){
			scene.addObject(objects.createResource(new Object(
					shapes.createResource(shape), materials.createResource(material))));
	};

	auto addLamp = [&](Lamp* l){
			lSet.push_back(lamps.createResource(l));
	};


	PyObject * presult = parse(argc, argv); // Result of .scn parsing

	PyObject * parameters = PyList_GetItem(presult, 0); // a tuple.
	PyObject * current_object;

	const unsigned int width = PyInt_AsLong(PyTuple_GetItem(parameters,2));
	const unsigned int height = PyInt_AsLong(PyTuple_GetItem(parameters,3));
	const unsigned int nb_objects = PyInt_AsLong(PyTuple_GetItem(parameters,1));
	const unsigned int nb_displayer = PyInt_AsLong(PyTuple_GetItem(parameters,4));
	const unsigned int layout_i = PyInt_AsLong(PyTuple_GetItem(parameters,5));
	const unsigned int layout_j = PyInt_AsLong(PyTuple_GetItem(parameters,6));

	for (unsigned int i = 1 ; i <= nb_objects ; ++i) {
		current_object = PyList_GetItem(presult, i);
		switch (PyInt_AsLong(PyTuple_GetItem(current_object,0))) {
			case 0 : // Sphere
				addObject(new Sphere(point_from_tuple(PyTuple_GetItem(current_object,2)),
														 PyInt_AsLong(PyTuple_GetItem(current_object,3))),
									new Material(get_material(PyInt_AsLong(PyTuple_GetItem(current_object,1)))));
				break;
			case 1 : // Triangle
				addObject(new Triangle(point_from_tuple(PyTuple_GetItem(current_object,2)),
															 point_from_tuple(PyTuple_GetItem(current_object,3)),
															 point_from_tuple(PyTuple_GetItem(current_object,4))),
									new Material(get_material(PyInt_AsLong(PyTuple_GetItem(current_object,1)))));
				break;
			case 2 : // Plane
				break;
			case 3 : // LampPoint
				addLamp(new LampPoint(scene, point_from_tuple(PyTuple_GetItem(current_object,1))));
				break;
			default :
				cout << "Error : cannot determine type" << endl;
				break;
		}
	}

	std::vector<CollisionManager*> collisionManagers = {
			//new CollisionManager(new Light_ZBuffer),
			// new CollisionManager(new Light_Basic),
			new CollisionManager(new Light_Multi(lSet)),
			new CollisionManager(new Light_Multi(lSet)),
			new CollisionManager(new Light_Multi(lSet)),
			new CollisionManager(new Light_Multi(lSet))
	};

	WindowManager displayers(Layout(layout_i,layout_j), width, height);
	std::vector<std::pair<unsigned int, unsigned int>> pos = {
			std::make_pair(0u, 0u),
			std::make_pair(0u, 1u),
			std::make_pair(1u, 0u),
			std::make_pair(1u, 1u)
	};

	std::vector<Camera> cameras = {
			Camera(absolut_origin, PolarCoordinates(-0.30, 0.), width, height, 1., 1.),
			Camera(absolut_origin, PolarCoordinates(-0.15, 0.), width, height, 1., 1.),
			Camera(absolut_origin, PolarCoordinates( 0.15, 0.), width, height, 1., 1.),
			Camera(absolut_origin, PolarCoordinates( 0.30, 0.), width, height, 1., 1.)
	};

	std::vector<std::unique_ptr<RaytracerEngine>> engines;
	for (unsigned int i = 0; i < collisionManagers.size(); ++i) {
			engines.emplace_back(new RaytracerEngine(
					scene,
					displayers(pos[i].first, pos[i].second),
					collisionManagers[i]));
			engines[i]->updateScreen(Color::Black, cameras[i]);
	}

	// Render Loop
	sf::RenderWindow window(displayers.fitIn(1036,832), "RaytracerEngine");
	while (window.isOpen()) {

			window.clear();
			window.draw(displayers);
			window.display();

			sf::Event event;
			if(window.waitEvent(event)) {
					if (event.type == sf::Event::Closed)
							window.close();
			}
	}
	return 0;
}
