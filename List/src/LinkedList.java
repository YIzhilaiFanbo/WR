public class LinkedList implements List {
    private Node front; // 头节点
    private Node rear; // 尾节点

    // 构造函数
    public LinkedList() {
        front = null;
        rear = null;
    }

    @Override
    public boolean listEmpty() {
        return front == null;
    }

    @Override
    public int listLength() {
        int length = 0;
        Node current = front;
        while (current != null) {
            length++;
            current = current.next;
        }
        return length;
    }

    @Override
    public int getInt(int i) {
        if (i <= 0 || i > listLength()) {
            return -1; // 或者抛出异常表示未找到
        }
        int count = 1;
        Node current = front;
        while (current != null) {
            if (count == i) {
                return current.data;
            }
            count++;
            current = current.next;
        }
        return -1; // 或者抛出异常表示未找到
    }

    @Override
    public int locateInt(int e) {
        int index = 1;
        Node current = front;
        while (current != null) {
            if (current.data == e) {
                return index;
            }
            index++;
            current = current.next;
        }
        return -1;
    }

    @Override
    public void listInsert(int i, int e) {
        if (i < 0 || i > listLength() + 1) {
            // 插入位置非法，可以抛出异常或者进行其他处理
            return;
        }
        Node newNode = new Node(e);
        if (i == 1) {
            newNode.next = front;
            front = newNode;
            if (rear == null) {
                rear = front;
            }
        } else if (i == listLength() + 1) {
            rear.next = newNode;
            rear = newNode;
        } else {
            int count = 1;
            Node current = front;
            while (count < i - 1) {
                current = current.next;
                count++;
            }
            newNode.next = current.next;
            current.next = newNode;
        }
    }

    @Override
    public int listDelete(int i) {
        if (i <= 0 || i > listLength()) {
            return -1; // 或者抛出异常表示未找到
        }
        if (i == 1) {
            int deletedData = front.data;
            front = front.next;
            if (listLength() == 1) {
                rear = null;
            }
            return deletedData;
        } else {
            int count = 1;
            Node current = front;
            while (count < i - 1) {
                current = current.next;
                count++;
            }
            int deletedData = current.next.data;
            current.next = current.next.next;
            if (i == listLength()) {
                rear = current;
            }
            return deletedData;
        }
    }

    @Override
    public void listUpdate(int i, int e) {
        if (i <= 0 || i > listLength()) {
            // 更新位置非法，可以抛出异常或者进行其他处理
            return;
        }
        int count = 1;
        Node current = front;
        while (count < i) {
            current = current.next;
            count++;
        }
        current.data = e;
    }

    @Override
    public void clearList() {
        front = null;
        rear = null;
    }
    public int GetHead() {
        if (front != null) {
            return front.data;
        }
        return -1;
    }

    // Node 节点类的定义
    private static class Node {
        public int data; // 数据
        public Node next; // 指向下一个节点的指针

        public Node(int data) {
            this.data = data;
            this.next = null;
        }
    }
}
