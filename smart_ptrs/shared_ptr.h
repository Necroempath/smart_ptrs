#pragma once
template <typename T>
class shared_ptr
{
	T* _ptr;
	shared_ptr* array;
	size_t _use_count;

public:
	shared_ptr() : _ptr(nullptr), _use_count(0) {}

	shared_ptr(T&& obj) : _ptr(new T(obj)), _use_count(1) {}

	shared_ptr(const shared_ptr& other) : _ptr(other._ptr), _use_count(other._use_count + 1) {}

	shared_ptr(shared_ptr&& other) noexcept : _ptr(other._ptr), _use_count(other._use_count) { other._ptr = nullptr; }

	shared_ptr& operator=(const shared_ptr& other)
	{
		if (this == &other) return *this;
		_ptr = other._ptr;
		_use_count = other._use_count + 1;

		return *this;
	}

	shared_ptr& operator=(shared_ptr&& other) noexcept
	{
		if (this == &other) return *this;

		reset();
		_ptr = other._ptr;
		_use_count = other._use_count;
		other._ptr = nullptr;

		return *this;
	}

	const T* operator[](const long index)

	T* operator->()
	{
		return _ptr;
	}

	T& operator*()
	{
		return *_ptr;
	}

	explicit operator bool() const { return _ptr != nullptr; }

	T* get() const { return _ptr; }

	size_t use_count() const { return _use_count; }

	shared_ptr& swap(shared_ptr& other)
	{
		T* temp = _ptr;
		_ptr = other._ptr;
		other._ptr = temp;

		return *this;

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

	~shared_ptr() { if (_ptr && _use_count == 0) delete _ptr; }
};

