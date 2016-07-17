import java.util.*;

class Circle {
    public int circle(int n, int m) {
        if (n < 1 || m < 1)
            return(-1);
        List<Integer> list = new LinkedList<>();
        for (int i = 0; i < n; i++)
            list.add(i);
        int p = 0;
        while (true) {
            if (list.size() == 1)
                break;
            for (int i = 0; i < m - 1; i++)
                if (++p >= list.size())
                    p = 0;
            list.remove(p);
            if (p >= list.size())
                p = 0;
        }
        return list.get(0);
    }
    public static void main(String[] args) {
        Circle cc = new Circle();
        System.out.println(cc.circle(5, 1));
        System.out.println(cc.circle(5, 3));
    }
}
