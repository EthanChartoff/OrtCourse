import java.util.Set;

public class RecyclableProduct extends Product implements IRecyclable {
    private String recycleOption;

    public RecyclableProduct(Set<Material> materialSet, String name, String reduce, String recycleOption) {
        super(materialSet, name, reduce);
        this.recycleOption = recycleOption;
    }

    @Override
    public String recycleOption() {
        return recycleOption;
    }
}
