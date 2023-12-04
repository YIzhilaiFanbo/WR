public interface List {
    boolean listEmpty(); // 是否为空表，若为空表，返回True，否则False

    int listLength(); // 返回数据元素个数

    int getInt(int i); // 返回第i个数据元素的值

    int locateInt(int e); // 返回表中e的次序，若不存在，返回-1

    void listInsert(int i, int e); // 在i位置插入元素e

    int listDelete(int i); // 删除i位置元素并返回该元素

    void listUpdate(int i, int e); // 更新i位置元素

    void clearList(); // 清空列表
}
