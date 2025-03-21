#pragma once
template <typename T>
class shared_ptr
{
	T* _ptr;
	size_t* _use_count;
	
	bool decrease_count()
	{
		if(_use_count != nullptr)
		{
			if (*_use_count >= 0) return --(*_use_count) == 0;			
		}

		return 0;
	}

public:
	shared_ptr() : _ptr(nullptr), _use_count(new size_t(0)) {}

	shared_ptr(T&& obj) : _ptr(new T(obj)), _use_count(new size_t(1)) {}

	shared_ptr(const shared_ptr& other) : _ptr(other._ptr), _use_count(other._use_count) { (*_use_count)++; }

	shared_ptr(shared_ptr&& other) noexcept : _ptr(other._ptr), _use_count(other._use_count)
	{ 
		other._ptr = nullptr; 
		other._use_count = nullptr;
	}

	shared_ptr& operator=(const shared_ptr& other)
	{
		if (this == &other) return *this;
		if (decrease_count()) {
			delete _ptr;
			delete _use_count;
		}

		_ptr = other._ptr;
		_use_count = other._use_count;
		(*_use_count)++;

		return *this;
	}

	shared_ptr& operator=(shared_ptr&& other) noexcept
	{
		if (this == &other) return *this;
		if (decrease_count()) {
			delete _ptr;
			delete _use_count;
		}

		_ptr = other._ptr;
		_use_count = other._use_count;

		other._ptr = nullptr;
		other._use_count = nullptr;

		return *this;
	}

	T* operator->()
	{
		return get();
	}
	
	T& operator*()
	{
		return *_ptr;
	}

	explicit operator bool() const { return _ptr != nullptr; }

	inline T* get() const { if(_ptr) return _ptr; }

	inline size_t use_count() const { if(_use_count) return *_use_count; }

	void swap(shared_ptr& other)
	{
		T* temp_ptr = _ptr;
		size_t* temp_count = _use_count;

		_ptr = other._ptr;
		_use_count = other._use_count;

		other._ptr = temp_ptr;
		other._use_count = temp_count;
	}

	inline bool unique() const { return use_count() == 1; }

	inline T* release()
	{
		if (!_ptr) return nullptr;
		if (decrease_count()) {
			delete _ptr; 
			delete _use_count;
		}

		T* temp = _ptr;
		_ptr = nullptr;

		return temp;
	}
	
	~shared_ptr() 
	{ 
		if (!_use_count) return;
		if (*_use_count >= 0) (*_use_count)--;
		if (_ptr && *_use_count == 0) 
			delete _ptr; 
	}
};

