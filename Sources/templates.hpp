#ifndef TEMPLATES_HPP_
#define TEMPLATES_HPP_

namespace sfy {

template <typename T>
int compare(const T &v1, const T &v2)
{
	if (v1 < v2) return -1;
	if (v2 < v1) return 1;
	return 0;
}

// Queue template
template <class T>
class Queue {
public:
	Queue();
	T &front();

	const T &front() const;
	void push(const T &);
	void pop();
	bool empty() const;
};

}

#endif /* TEMPLATES_HPP_ */
