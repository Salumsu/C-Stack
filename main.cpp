#include <iostream>

using namespace std;

class Stack{
private:
    int top; // variable for monitoring the top element
    int * arr;  // main dynamic array
    int * temp; // temporary dynamic array
public:
    Stack() { // constructor for the class
        top = -1; // instantiate top to -1
        arr = new int[0]; // instantiate main array
    }

    void push(int n){ // method for adding element
        top++; // increments top to 1
        temp = new int[top+1]; // instantiate temporary array with a size 1 more than the size of main array
        if(top > 0){ // copy the main array
            for(int i = 0; i < top; i++){
                temp[i] = arr[i];
            }
        }

        temp[top] = n; // instantiate last index of temporary array with the new element
        arr = temp; // assign the values of temporary array to main array
    }

    int pop(){ // method for popping top element
        if(!isEmpty()){ // check if array is empty
            int n = arr[top]; // take the top element and assign it to n
            temp = new int[top]; // instantiate temporary array with a size 1 less than the size of main array
            top--; // decrement top by 1
            for(int i = 0; i < top + 1; i++){ // assign main array elements to temporary array except the top element
                temp[i] = arr[i];
            }
            arr = temp; // assign the elements of the temporary array to the main array
            return n; // return the popped value
        }

        return 0;
    }

    void display(){ // method for displaying the elements of the main array
        if(!isEmpty()){ // check if array is empty
            cout << "Stack Elements are: ";
            for(int i = top; i > -1; i--){ // traverse the elements of the array and display them from top element to the bottom
                cout << arr[i] << " ";
            }
            cout << endl;
        } else {
            cout << "The stack have no elements" << endl;
        }
    }

    bool isEmpty(){ // method for checking if the array is empty
        if(top == -1)
            return true;
        return false;
    }

    void exit(){ // clean up method
        delete [] arr;
        delete [] temp;
    }

};

int main(){
    Stack myStack; // instantiate myStack as a Stack

    int onGoing = true; // instantiate onGoing to true
    int choice; // variable for storing the choice
    while(onGoing){
        cout << "Enter choice: ";
        cin >> choice;
        if(choice == 1){
            int n;
            cout << "Enter value to be pushed: ";
            cin >> n;
            myStack.push(n);
        } else if(choice == 2){
            if(myStack.isEmpty()){
                cout << "Array is Empty" << endl;
            } else {
              cout << "The popped element is " << myStack.pop() << endl;
            }
        } else if(choice == 3){
            myStack.display();
        } else if(choice == 4){
            cout << "Exit" << endl;
            onGoing = false;
        } else {
            cout << "Invalid Choice" << endl;
        }
    }
    
    myStack.exit();
}
