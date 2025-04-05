#pragma once
template <typename T>
class unique_ptr
{
	T* _ptr;

public:
	unique_ptr() : _ptr(nullptr) {}

	unique_ptr(T&& obj) : _ptr(new T(obj)) {}

	unique_ptr(const unique_ptr& obj) = delete;

	unique_ptr(unique_ptr&& other) noexcept : _ptr(other._ptr) { other._ptr = nullptr; }

	unique_ptr& operator=(unique_ptr&& other) noexcept
	{
		if (this == &other) return *this;

		reset();
		_ptr = other._ptr;
		other._ptr = nullptr;

		return *this;
	}

	T* operator->()
	{
		if (_ptr) return _ptr;
	}

	T& operator*()
	{
		return *_ptr;
	}

	explicit operator bool() const { return _ptr != nullptr; }

	inline T* get() const { if(_ptr) return _ptr; }

	void swap(unique_ptr& other)
	{
		T* temp = _ptr;
		_ptr = other._ptr;
		other._ptr = temp;
	}

	inline void reset(T* ptr = nullptr)
	{
		if (!_ptr) return;

		delete _ptr;
		_ptr = ptr;
	}

	inline T* release()
	{
		if (!_ptr) return nullptr;

		T* temp = _ptr;
		_ptr = nullptr;
		return temp;
	}

	~unique_ptr() { if (_ptr) delete _ptr; }
};

