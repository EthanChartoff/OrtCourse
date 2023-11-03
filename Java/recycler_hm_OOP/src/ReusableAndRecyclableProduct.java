import java.util.Set;

public class ReusableAndRecyclableProduct extends Product implements IRecyclable, IReusable {
    private String recycleOption, reuseOption;

    public ReusableAndRecyclableProduct(
            Set<Material> materialSet,
            String name,
            String reduce,
            String recycleOption,
            String reuseOption
    ) {
        super(materialSet, name, reduce);
        this.recycleOption = recycleOption;
        this.reuseOption = reuseOption;
    }

    @Override
    public String recycleOption() {
        return recycleOption;
    }

    @Override
    public String reuseOption() {
        return reuseOption;
    }
}
