import java.util.*;



public class Main {
    public static Map<String, Integer> wordCount(String[] strings) {
        Map<String, Integer> count = new HashMap<>();
        int curr;

        for (String s : strings) {
            if(count.containsKey(s)) {
                count.replace(s, count.get(s) + 1);
            } else {
                count.put(s, 1);
            }
        }
        return count;
    }

    public static void main(String[] args) {
        // Q1
//        ArrayList<Integer> arrayList = new ArrayList<>();
//        arrayList.add(2);
//        arrayList.get(0);
//        arrayList.size();
//        arrayList.isEmpty();
//        arrayList.clear();
//
//        LinkedList<Float> linkedList = new LinkedList<>();
//        linkedList.add(1.2f);
//        linkedList.get(0);
//        linkedList.addFirst(1f);
//        linkedList.size();
//        linkedList.clear();
//
//        HashSet<Double> hashSet = new HashSet<>();
//        hashSet.add(3.2);
//        hashSet.size();
//        hashSet.clear();
//        hashSet.toArray();
//        hashSet.spliterator();
//
//        HashMap<Integer, Character> hashMap = new HashMap<>();
//        hashMap.put(1, 'a');
//        hashMap.get(0);
//        hashMap.isEmpty();
//        hashMap.remove(0);
//        hashMap.clear();

        // Q2a
//        Circle circle = new Circle (42);
//        ColoredCircle coloredCircle = new ColoredCircle (42, "red");
//        System.out.println(coloredCircle.equals(circle));
//        System.out.println(circle.equals(coloredCircle));

        // Q2b
//        Map<Team,String> leaders = new HashMap<>();
//        leaders.put(new Team("New York", "development"), "Anne");
//        leaders.put(new Team("Boston", "development"), "Brian");
//        leaders.put(new Team("Boston", "marketing"), "Charlie");
//        Team myTeam = new Team("New York", "development");
//        System.out.println(leaders.get(myTeam));

        // Q3
        System.out.println(wordCount(new String[] {"c", "c", "c", "a"}));

    }
}