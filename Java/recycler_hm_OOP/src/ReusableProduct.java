import java.util.Set;

public class ReusableProduct extends Product implements IReusable {
    private String reuseOption;

    public ReusableProduct(Set<Material> materialSet, String name, String reduce, String reuseOption) {
        super(materialSet, name, reduce);
        this.reuseOption = reuseOption;
    }

    @Override
    public String reuseOption() {
        return reuseOption;
    }
}
