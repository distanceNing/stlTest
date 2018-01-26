#ifndef _YN_STL_QUEUE_
#define _YN_STL_QUEUE_
#include <list>
#include <cassert>
namespace ynstl{
template < class T>
class Queue
{
public:
	typedef T value_type;
	Queue() {}

	~Queue(){}

	bool empty()const {
		return queue_.empty();
	}
	
	void push(T data) {
		queue_.push_back(data);
	}
	value_type back()const {
		return queue_.back();
	}

	value_type front()const {
		return queue_.front();
	}

	void pop() {
		assert(!queue_.empty());
		queue_.pop_front();
	}
	
	size_t size()const { return queue_.size(); }
private:
	std::list<value_type> queue_;
};
}// namespace ynstl

#endif // !_QUEUE
