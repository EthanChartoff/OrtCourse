import java.util.List;
import java.util.Set;

public class Consumerism {
    public static void analysis(Product product) {
        System.out.println("Composition");
        Set<Material> materialSet = product.getMaterialSet();

        int counter = 1;
        for(Material m : materialSet){
            System.out.printf("%d. %s, takes %d years to decay\n", counter, m.name(), m.timeToDecay());
            counter++;
        }

        System.out.println(product.getName() + " takes " + product.timeToDecay() + " years to decay");
        if(product instanceof IReusable)
            System.out.println("Reuse option: " + ((IReusable) product).reuseOption());

        if(product instanceof IRecyclable)
            System.out.println("Recycle option: " + ((IRecyclable) product).recycleOption());
    }

    public static void main(String[] args) {
        Material aluminium = new Material("aluminium", 200);
        Material plastic = new Material("Plastic", 450);

        Product printer = new RecyclableProduct(Set.of(aluminium, plastic), "Printer", "print less", "ink in store");
        Product bag = new ReusableAndRecyclableProduct(Set.of(plastic), "plastic bag", "use chests", "recycle old bag", "use until you can");

        analysis(printer);
        analysis(bag);
    }
}
