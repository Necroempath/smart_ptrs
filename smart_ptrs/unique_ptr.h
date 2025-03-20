#pragma once
template <typename T>
class unique_ptr
{
	T* _ptr;

public:
	unique_ptr() { _ptr = nullptr; }

	unique_ptr(T&& obj) : _ptr(new T(obj)) {}

	unique_ptr(unique_ptr&& other) noexcept : _ptr(other._ptr) { other._ptr = nullptr; }

	unique_ptr& operator=(unique_ptr&& other) noexcept
	{
		if (this == &other) return *this;

		_ptr = other._ptr;
		other._ptr = nullptr;

		return *this;
	}

	T* operator->()
	{
		return _ptr;
	}

	T& operator*()
	{
		return *_ptr;
	}

	explicit bool operator bool() const { return _ptr != nullptr; }

	T* get() const { return _ptr; }

	inline void reset(T* ptr = nullptr)
	{
		delete _ptr;
		_ptr = ptr;
	}

	inline T* release()
	{
		T* temp = _ptr;
		_ptr = nullptr;
		return temp;
	}

	~unique_ptr() { if (_ptr) delete _ptr; }
};

