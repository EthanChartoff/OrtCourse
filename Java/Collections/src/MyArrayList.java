import java.util.Arrays;

public class MyArrayList<T> {
    private static final int DEFAULT_SIZE = 10;
    private static final Object[] EMPTY_ELEMENTDATA = {};
    transient Object arr[];
    private int size;


    public MyArrayList() {
        this.arr = new Object[DEFAULT_SIZE];
        this.size = DEFAULT_SIZE;
    }

    public MyArrayList(int size) {
        if(size > 0) {
            this.arr = new Object[size];
            this.size = size;
            for (int i = 0; i < this.arr.length; i++) {
                this.arr[i] = null;
            }
        } else if(size == 0) {
            this.arr = EMPTY_ELEMENTDATA;
            this.size = 0;
        } else {
            throw new IllegalArgumentException("Illegal size: " + size);
        }
    }

    public void add(T element) {
        boolean nullFlag = false;
        int nullIndex = -1;

        for (Object e : this.arr) {
            if(e.equals(null)) {
                nullFlag = true;
                nullIndex = Arrays.stream(this.arr).toList().indexOf(e);
                break;
            }
        }
        if(nullFlag) {
            this.arr[nullIndex] = element;
        } else {
            Object[] tmp = new Object[(int) (this.size * 1.2)];
            Arrays.stream(tmp).toList().addAll(Arrays.stream(this.arr).toList());
            tmp[this.size] = element;
            this.size = (int) (this.size * 1.2);
            this.arr = tmp;
        }
        return;
    }

    public void remove(T element) {
        for (int i = 0; i < this.arr.length; ++i) {
            if(element.equals(this.arr[i])) {
                this.arr[i] = null;
                break;
            }
        }
        Object[] tmp = new Object[this.size--];
        for (int i = 0; i < this.arr.length; i++) {
            if(this.arr[i] != null) {
                tmp[i] = this.arr[i];
            }
        }
        this.arr = tmp;
    }

    public void removeAll(T element) {
        for (Object e : this.arr) {
            if(e.equals(element)) {
                remove(element);
            }
        }
    }

    public int getSize() {
        return size;
    }

    public void clear() {
        this.arr = new Object[DEFAULT_SIZE];
        this.size = DEFAULT_SIZE;
    }

    public MyArrayList<T> subList(int i, int j) {
        MyArrayList<T> sub = new MyArrayList<>(i - j);
        for(int k = 0; k < i - j; ++k) {
            sub.arr[k] = this.arr[k + j];
        }
        return sub;
    }
}
