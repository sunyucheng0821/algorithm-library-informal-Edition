#include<iostream>
#include<iterator>
#include<algorithm>
using namespace std;
template<class T>
struct _List_node{
	typedef void* void_pointer;
	void_pointer next;
	void_pointer prev;
		T data;
};
template<class T,class Ref,class Ptr>
class _List_iterator{
public:
	typedef _List_iterator<T, T&, T*> iterator;
	typedef _List_iterator<T, const T&, const T*> const_iterator;
	typedef _List_iterator<T, Ref, Ptr> self;
	typedef T value_type;
	typedef Ptr pointer;
	typedef Ref reference;
	typedef _List_node<T>* link_type;
	typedef size_t size_type;
	typedef ptrdiff_t difference_type;
	link_type node;
	_List_iterator(link_type x):node(x){}
	_List_iterator(){}
	_List_iterator(const iterator &x):node(x.node){}
	bool operator== (const iterator& x )const{return node == x.node;}
	bool operator!= (const iterator& x)const{return node != x.node;}
	reference operator*()const{return (*node).data;}
	pointer operator->()const{return &(operator*());}
	T operator *(){return node->data;}
	iterator &operator++(int){
		iterator tmp = *this;
		++*this;
		return tmp;
	}
	iterator& operator++(){
		node = (link_type)((*node).next);
		return *this;
	}
	iterator& operator--(){
		node = (link_type)((*node).prev);
		return *this;
	}
	iterator& operator--(int){
		iterator tmp = *this;
		--*this;
		return tmp;
	}
};
template<class T>
class List{
public:
	typedef _List_node<T>* link_type;
	typedef _List_iterator<T,T&,T*> iterator;
	typedef T value_type;
	typedef T* pointer;
	typedef T& reference;
	typedef size_t size_type;
	typedef ptrdiff_t difference_type;
protected:
	typedef _List_node<T> list_node;
	link_type node;
	//.....
public:
	List(){create_node();}
	List(List& alist){
		create_node();
		for(List<T>::iterator ite=alist.begin();ite!=alist.end();++ite)
			push_back(*ite);
	}
	iterator begin(){return (link_type)((*node).next);}
	iterator end(){return node;}
	bool empty()const{return node->next == node;}
	size_type size()const{
		size_type result = 0;
		distance(begin(),end(),result);
		return result;
	}
	reference front(){return *begin();}
	reference back(){return *(--end());}
	iterator insert(iterator position,const T& x){
		link_type tmp = create_node(x);
		tmp->next = position.node;
		tmp->prev = position.node->prev;
		(link_type(position.node->prev))->next = tmp;
		position.node->prev = tmp;
		return tmp;
	}
	link_type create_node(const T& x){
		link_type p = new list_node;
		p->data = x;
		p->prev = NULL;
		p->next = NULL;
		return p ;
	}
	void create_node(){
		node = new list_node();
		node->next = node;
		node->prev = node;
	}
	inline difference_type distance(iterator first,iterator last,difference_type &n){
		n = 0;
		while(first != last){++first;++n;}
		return n;
	}
	void push_front(const T& x){insert(begin(),x);}
	void push_back(const T& x){insert(end(),x);}
	void pop_front(){erase(begin());}
	void pop_back(){iterator tmp = end();erase(--tmp);}
	iterator erase(iterator position){
		link_type next_node = link_type(position.node->next);
		link_type prev_node = link_type(position.node->prev);
		prev_node->next = next_node;
		next_node->prev = prev_node;
		destory_node(position.node);
		return iterator(next_node);
	}
	iterator erase(iterator first,iterator last){
		while(first!=last){
			first = erase(first);
		}
		return last;
	}
	void destory_node(link_type p){delete p;}
	~List(){
		clear();
		delete node;
	}
	void clear()
    {
        while (!empty())
            pop_back();
    }
	iterator find(const T& value){
		iterator first = begin();
		while(first!= end()){
			if(*first == value)return first;
			++first;
		}
		return first;
	}
	void remove(const T& value){
		iterator first = begin();
		iterator last = end();
		while(first != last){
			if(*first == value)first = erase(first);
			else ++first;
		}
	}
	void transfer(iterator position,iterator first,iterator last){
		if(position != last){
			(*(link_type((*last.node).prev))).next = position.node;
			(*(link_type((*first.node).prev))).next = last.node;
			(*(link_type((*position.node).prev))).next = first.node;
			link_type tmp = link_type((*position.node).prev);
			(*position.node).prev = (*last.node).prev;
			(*last.node).prev = (*first.node).prev;
			(*first.node).prev = tmp;
		}
	}
	void splice(iterator position,List<T> &x){
		if(!x.empty())
			transfer(position,x.begin(),x.end());
	}
	void splice(iterator position,List<T> &,iterator i){
		iterator j = i;
		++j;
		if(position == i||position == j)return;
		transfer(position,i,j);
	}
	void splice(iterator position,List<T>&,iterator first,iterator last){
		if(first!=last)
			transfer(position,first,last);
	}
};