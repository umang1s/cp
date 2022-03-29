#include"default.h"
//STL overview.

void first_stl_introduction(){
    /*
        Containers
            Simple
                pair,vector,forward_list,list.
            Adapters
                stack,queue,priority_queue.
            Associative
                set,map,unordered_set,unorderd_map.

        Algorithms
            sort,search,find,reverse.
    */
   int arr[]={10,2,34,78,12};
   sort(arr,arr+4);
   for(int i=0; i<5; i++) cout<<arr[i]<<' ';
   //binary_search(begin_address,end_address,value)
   if(binary_search(arr,arr+4,2)) cout<<"found";

}

void second_stl_iterators(){
    /*  TYPES of operator.(5)
	        input
	        output
	        forward
	        bidirectional
	        random
        
	    Containers
	    	Simple
	    		Forward_list	Forward
	    		list		    bidirectional
	    		vector		    random
	    	Associative
	    		set		        bidirectional
	    		map		        bidirectional
	    		multimap	    bidirectional
	    		multiset	    bidirectional
    
	    		unordered_set	forward
	    		unordered_map	forward
	    	Adapters
	    		queue		do not have iterators
	    		stack
	    		priority_queue



        let pnt--> vector<T>::iterator 	//pnt is different from pointer.

        begin()-->return pnt of begin
        end()  -->return pnt of end
        prev(pnt) -->return pnt of previous
        next(pnt) -->return pnt of next
        advance(pnt,int) -->move pnt to next int position.
    */
   vi arr={1,5,2,9,3};
   vector<int>::iterator i=arr.begin();
   cout<<*i<<' ';//1
   i++;
   cout<<*i<<' '; //5

   i=prev(i,1);//i goes to next position
   advance(i,2);//i goes to next two position
}

void third_templates(){
    /*
        Write once,use for any data type.
        Like macros processed by compiler but better than macros as typing checking is performed.
        Types 2.
            Function templates
                sort,linear search,binary search.
                //template<typename T>
                //T myMax(T x,T y){}
            Class templates
                stack,queue,deque.

        difference between macros and templates.
        templates
            template<typename T>
            T myMax(T x,T y){
                return( x>y) > x:y;
            }
        macros
            # myMax(x,y) ((x>y)?x:y

    */
}

void first_templates(){
    /*
    Types.2
        Function templates
            template<typename,T>
            T function_name(T val){
                T x;
                return x;
            }
        Class templates.

    Difference between macros and templates. 
    macros
        # function_name(val) return val
    */

}

void solve(){
    first_stl_introduction();

}