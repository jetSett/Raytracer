#ifndef OPTIONAL_HPP
#define OPTIONAL_HPP

#include <iostream>
#include <memory>


/// \class Optional
/// \brief A class to contain data that can have a bad value you have to use it when you can't be sure of the return of a function
/// For example in the normal function : you return an optional which contains the value of the normal iif the point is inside the Shape
/// \author Guillaume Bouchard

template<typename T>
class Optional
{
private:
	struct Empty_
	{};

	union{
		T _t;
		Empty_ _empty;
	};

	bool _isOk;


public:
	Optional()
		:_isOk(false)
	{}

	explicit Optional(T t)
		:_t(std::move(t)), _isOk(true)
	{}

	Optional(Optional &&o)
		:_isOk(o._isOk)
	{
		if(_isOk)
		{
			_t = std::move(o._t);
		}
	}

	~Optional()
	{
		if(_isOk)
		{
			_t.~T();
		}
	}
	/// \fn ok
	/// \return true if the optional is initialised, else false
	bool ok() const
	{
		return _isOk;
	}

	void assign(T t){
		if(_isOk)
		{
			_t.~T();
		}
		_isOk = true;
		_t = t;
	}


	/// \fn ifOp
	/// \brief execute the function f (which takes in parameter a T object) iif the object is initialised*
	/// \example
	/// 	Optional<int> notEmpty(10);
	/// 	notEmpty.ifOp([] (int &i)
	/// 	{
	/// 		i *= 2;
	/// 		std::cout << i << " est valide !" << std::endl;
	///		});
	template<typename F>
	void ifOp(F f) &
	{
		if(_isOk)
		{
			f(_t);
		}
	}

	template<typename F>
	void ifOp(F f) &&
	{
		if(_isOk)
		{
			f(std::move(_t));
		}
	}

	template<typename F>
	void ifOp(F f) const &
	{
		if(_isOk)
		{
			f(_t);
		}
	}

	template<typename F>
	void ifOp(F f) const &&
	{
		if(_isOk)
		{
			f(std::move(_t));
		}
	}

	/// \fn ifelseOp
	/// \brief execute the function f (which takes in parameter a T object) if the object is initialised, else execute the function g
	/// \example
	/// 	Optional<int> empty;
	/// 	notEmpty.ifelseOp([] (int &i)
	/// 	{
	/// 		i *= 2;
	/// 		std::cout << i << " est valide !" << std::endl;
	///		},
	///		[] (){
	///			std::cout << "non initilisé" << std::endl;
	///		});
	template<typename F, typename G>
	void ifelseOp(F f, G g) &
	{
		if(_isOk)
		{
			f(_t);
		}else{
			g();
		}
	}

	template<typename F, typename G>
	void ifelseOp(F f, G g) &&
	{
		if(_isOk)
		{
			f(std::move(_t));
		}else{
			g();
		}
	}

	template<typename F, typename G>
	void ifelseOp(F f, G g) const &
	{
		if(_isOk)
		{
			f(_t);
		}else{
			g();
		}
	}

	template<typename F, typename G>
	void ifelseOp(F f, G g) const &&
	{
		if(_isOk)
		{
			f(std::move(_t));
		}else{
			g();
		}
	}

	/// \fn ifelseOpReturn
	/// \brief execute the function f (which takes in parameter a T object) if the object is initialised and return it result, else execute the function g and return its result
	/// \warning Those functions must return the same type
	/// \example
	/// 	Optional<int> empty;
	/// 	notEmpty.ifelseOpReturn([] (int &i)
	/// 	{
	/// 		i *= 2;
	/// 		std::cout << i << " est valide !" << std::endl;
	///			return i*3;
	///		},
	///		[] (){
	///			std::cout << "non initilisé" << std::endl;
	///			return 0;
	///		});
	template<typename F, typename G, typename H>
	H ifelseOpReturn(F f, G g) &
	{
		if(_isOk)
		{
			return f(_t);
		}else{
			return g();
		}
	}

	template<typename H, typename F, typename G>
	H ifelseOpReturn(F f, G g) &&
	{
		if(_isOk)
		{
			return f(std::move(_t));
		}else{
			return g();
		}
	}

	template<typename H, typename F, typename G>
	H ifelseOpReturn(F f, G g) const &
	{
		if(_isOk)
		{
			return f(_t);
		}else{
			return g();
		}
	}

	template<typename H, typename F, typename G>
	H ifelseOpReturn(F f, G g) const &&
	{
		if(_isOk)
		{
			return f(std::move(_t));
		}else{
			return g();
		}
	}
};

#endif
