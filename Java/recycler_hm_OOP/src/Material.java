public record Material(String name, int timeToDecay) implements IDisposable, Comparable<Material> {

    @Override
    public int compareTo(Material o) {
        return timeToDecay - o.timeToDecay;
    }
}
