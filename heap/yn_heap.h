#ifndef _BIN_HEAP_H_
#define _BIN_HEAP_H_

#include <vector>
#include <cassert>
namespace ynstl{
template <class T>
class BinHeap
{
public:
	typedef T value_type;
	BinHeap() {}
	~BinHeap() {}

	void insert(value_type data) {
		heap_.push_back(data);
		adjust_up(heap_.size() - 1);
	}

	void adjust_up(size_t index) {
		value_type data = heap_[index];
		int parent = index / 2;
		while (data < heap_[parent]){
			std::swap(heap_[index], heap_[parent]);
			index = parent;
			parent = parent / 2;
		}
	}
	bool empty()const{
		return heap_.size() - 1 == 0;
	}

	// //删除二叉堆中的最小结点,返回最小元素
	value_type  min() {
		assert(!heap_.empty());
		T ret = heap_[1];
		heap_[1] = heap_.back();
		heap_.pop_back();
		int child;
		size_t size = heap_.size();
		//adjust down
		for (int i = 1; i * 2 < size;i = child){
			child = i * 2;
			if (child + 1 < size&&heap_[child] > heap_[child + 1]){
				child++;
			}
			if (heap_[i] > heap_[child]){
				std::swap(heap_[i], heap_[child]);
			}else{
				break;
			}
		}
		return ret;
	}

	void makeHeap(T Elements[], int size) {
		for (int i = 0;i < size;++i)
			insert(Elements[i]);
	}
private:
	std::vector<T> heap_;
};
}// namespace ynstl
#endif //!_BIN_HEAP_H_