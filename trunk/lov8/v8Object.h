#ifndef V8_OBJECT_H
#define V8_OBJECT_H

template<class T>
class WrappedObject {
public:

	WrappedObject(T p) : p(p),type(0) {
	}

	void setType(int type) {
		this->type = type;
	}

	int getType() {
		return type;
	}

	T unwrap() {
		return p;
	}

private:
	T p;
	int type;
};

#endif V8_OBJECT_H