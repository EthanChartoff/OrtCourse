import java.util.Collection;
import java.util.Collections;
import java.util.Comparator;
import java.util.Set;

public abstract class Product implements IDisposable, IReducible {
    private Set<Material> materialSet;
    private String name;
    private String reduce;


    public Product(Set<Material> materialSet, String name, String reduce) {
        this.materialSet = materialSet;
        this.name = name;
        this.reduce = reduce;
    }

    public Set<Material> getMaterialSet() {
        return materialSet;
    }

    public String getName() {
        return name;
    }

    public String getReduce() {
        return reduce;
    }

    @Override
    public int timeToDecay() {
        return longestDecayMaterial().timeToDecay();
    }

    @Override
    public String reduceOption() {
        return reduceOption();
    }

    private Material longestDecayMaterial() {
        return Collections.max(materialSet, Comparator.comparingInt(Material::timeToDecay));
    }


}
