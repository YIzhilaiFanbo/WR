public class Main {
    public static void main(String[] args) {
        LinkedList l=new LinkedList();
        l.listInsert(1,1);
        l.listInsert(2,2);
        l.listInsert(3,3);
        l.listInsert(4,4);
        if(l.listEmpty()){
            System.out.println("链表为空");
        }else{
            System.out.println("链表不为空");
        }
        System.out.println("链表长度："+l.listLength());
        System.out.println("链表为第4个元素："+l.getInt(4));
        System.out.println("链表中“3”的位置："+l.locateInt(3));
        System.out.println("链表被删去元素："+l.listDelete(3));
        System.out.println("链表中第3个元素："+l.getInt(3));
        l.listUpdate(3,3);
        System.out.println("链表中第3个元素："+l.getInt(3));
        System.out.println("链表中第1个元素："+l.GetHead());
        l.clearList();
        if(l.listEmpty()){
            System.out.println("链表为空");
        }else{
            System.out.println("链表不为空");
        }
    }
}