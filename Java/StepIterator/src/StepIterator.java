import java.util.Collection;
import java.util.Iterator;

public class StepIterator<T> implements Iterator<T> {
    private int step;
    private Iterator<T> iterator;

    public StepIterator(int step, Collection collection) {
        this.step = step;
        this.iterator = collection.iterator();
    }

    @Override
    public boolean hasNext() {
        return iterator.hasNext();
    }

    @Override
    public T next() {
        for(int i = 1; i < step && iterator.hasNext(); ++i) {
            iterator.next();
        }
        if(iterator.hasNext())
            return iterator.next();
        return null;
    }

    public void print() {
        T val = iterator.next();
        do {
            System.out.println(val);
            val = next();
        } while (val != null);
    }
}
