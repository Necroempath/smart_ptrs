#pragma once

template <typename T>
class shared_ptr
{
#pragma once

		T* _ptr;

	public:
		shared_ptr() { _ptr = nullptr; }

		shared_ptr(T& obj) : _ptr(new T(obj)) {}

		shared_ptr(T&& obj) : _ptr(new T(obj)) {}

		shared_ptr(const shared_ptr& other) : _ptr(other._ptr) {}

		shared_ptr(shared_ptr&& other) noexcept : _ptr(other._ptr) { other._ptr = nullptr; }

		shared_ptr& operator=(shared_ptr&& other) noexcept
		{
			if (this == &other) return *this;

			_ptr = other._ptr;
			other._ptr = nullptr;

			return *this;
		}

		shared_ptr& operator=(const shared_ptr& other)
		{
			if (this == &other) return *this;

			_ptr = other._ptr;

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

		T* get() const { return _ptr; }

		~shared_ptr() { if (_ptr) delete _ptr; }

};

