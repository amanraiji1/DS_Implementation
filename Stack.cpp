template <typename T>
class Stack{
	
	T *data;
	int nextIndex;
	int capacity;
	
	public:
		
		Stack(){
			data = new T[5];
			nextIndex = 0;
			capacity = 5;
		}
		
		//get size of stack
		int size(){
			return nextIndex;
		}
		
		//check if stack is empty
		bool isEmpty(){
			return nextIndex == 0;
		}
		
		//get top element
		T top(){
			if(isEmpty()){
				cout << "Stack Empty" << endl;
				return 0;
			}
			
			return data[nextIndex-1];	
		}
		
		//insert element
		void push(T element){
			if(nextIndex == capacity){
				T *newData = new T[2*capacity];
				for(int i=0;i<capacity;i++)
					newData[i] = data[i];
					
				delete []data;
				data = newData;
			}
			
			data[nextIndex] = element;
			nextIndex++;
		}
		
		//delete element
		T pop(){
			if(isEmpty()){
				cout << "Stack Empty" << endl;
				return 0;
			}
			
			nextIndex--;
			return data[nextIndex];
		}
};
