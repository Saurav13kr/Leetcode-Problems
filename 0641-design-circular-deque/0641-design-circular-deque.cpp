class MyCircularDeque {
    int *arr;
    int size;
    int front;
    int rear;

public:
    MyCircularDeque(int k) {
        size = k;
        arr = new int[k];
        front = -1;
        rear = -1;
    }

    bool insertFront(int value) {
        if (isEmpty()) {
            front++;
            rear++;
            // arr[front] = value;
        } else if (isFull()) {
            return false;
        }
        // single case
        else if (front == 0 && rear != size - 1) {
            front = size - 1;
            // arr[front] = value;
        }
        // normal case
        else {
            front--;
            // arr[front] = value;
        }
        arr[front] = value;
        return true;
    }

    bool insertLast(int value) {
        if (isFull())
            return false;
        if (isEmpty()) {
            front++;
            rear++;
            // arr[rear] = value;
        }
        // single element
        // else if (front == rear) {
        //     rear++;
        //     // arr[rear] = value;
        // }
        // circukar condn
        else if ((rear == size - 1) && front != 0) {
            rear = 0;
            // arr[rear] = value;
        } // normal case
        else {
            rear++;
        }
        arr[rear] = value;
        return true;
    }

    bool deleteFront() {
        if (isEmpty())
            return false;
        // single element
        int ans = arr[front];
        arr[front] = -1;
        if (front == rear) {
            // arr[front] = -1;
            front = -1;
            rear = -1;
        }
        // circular condition
        else if (front == size - 1) {
            //    arr[front] = -1;
            front = 0;
        }
        // normal case
        else {
            //    arr[front] = -1;
            front++;
        }
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) {
            return false;
        }
        // single element
        if (front == rear) {
            // arr[rear] = -1;
            rear = -1;
            front = -1;
        }
        // circular condition
        else if (rear == 0) {
            // arr[rear] = -1;
            rear = size - 1;
        }
        // normal condition
        else 
        {
            // arr[rear] = -1;
            rear--;
        }
        return true;
    }

    int getFront() {
        if (isEmpty()){
            return -1;}
        return arr[front];
    }

    int getRear() {
        if (isEmpty()){
            return -1;
        }
            
        return arr[rear];
    }

    bool isEmpty() {
        if (front == -1 && rear == -1) {
            return true;
        } else
            return false;
    }

    bool isFull() {
        if ((front == 0 and rear == size - 1) or
            ((front != 0) and (rear == (front - 1) % (size - 1)))) {
            return true;
        }
        return false;
    }
};
