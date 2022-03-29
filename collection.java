import java.util.*;
public class collection {
    /*
        Here we will learn about java collection.

        Collection interface is different from Collection framework. 
        Collection interface comes under Collection framework.

        Collection
            List (interface)
                ArrayList (class)
                LinkedList
                Stack
                Vector

            Set(interface)
                EnumSet
                HashSet
                LinkedHashSet
                TreeSet

            Queue(interface)
                ArrayDeque
                LinkedList
                PriorityQueue

        Map (interface)
            HashMap
            TreeMap
            EnumMap
            LinkedHashMap
            WeakHashMap
        
        Iterator
            ListIterator
    */


    public static void main(String [] argv){
        System.out.println("Starting");
        list();
    }

    public static void list(){
        List<Integer> list2=new ArrayList<>();
        List<Integer> list3=new LinkedList<>();
        List<Integer> list4=new Stack<>();
        List<Integer> list5=new Vector<>();

        Stack<Integer> stack=new Stack<>();
        Vector<Integer> vector=new Vector<>();
        LinkedList<Integer> linkedList=new LinkedList<>();
        Queue<Integer> second=new PriorityQueue<>(Comparator.reverseOrder());

        ArrayList<Integer> list=new ArrayList<>();

        list2.add(5);
        int size=list2.size();
        int num=list2.get(0);
        //list2.clear();
        
        Iterator<Integer> it=list2.iterator();
        while(it.hasNext()){
            System.out.println(it.next());
        }

        list4.add(43);
        list4.add(21);
        Iterator<Integer> it2=list4.iterator();
        while(it2.hasNext()) System.out.println(it2.next());


        Collections.min(list);
        Collections.max(list);
        Collections.reverse(list);
        Collections.frequency(list, 5);
        Collections.sort(list);
        Collections.sort(list,Comparator.reverseOrder());

        Collections.sort(list,new Comparator<Integer>() {
            @Override
            public int compare(Integer older,Integer newer){
                return older-newer;
            }
        });

        Collections.sort(list,(older,newer)->older.compareTo(newer));
        
    }

    public static void usingMap(){
        Map<String,Integer> mp=new HashMap<>();
        mp.put("First", 5);
        mp.put("Second", 4);

        for(Map.Entry<String,Integer> e: mp.entrySet()){
            System.out.println((e));
            e.getKey();
            e.getValue();

        }

        for(String key: mp.keySet()){

        }
        for(Integer value: mp.values()){

        }
    }
    
}


class Student implements Comparable<Student>{
    int rollno;
    String name;


    Student(){

    }
    Student(int roll,String name){
        this.rollno=roll;
        this.name=name;
    }

    @Override
    public String toString(){
        return "Students { Roll no : "+rollno+" , Name : "+name+" } ";
    }

    @Override
    public boolean equals(Object o){
        if(this==o) return true;
        if(o==null || getClass()!=o.getClass()) return false;
        Student student=(Student) o;
        return rollno==student.rollno;
    }

    @Override
    public int hashCode(){
        return Objects.hash(rollno);
    }

    @Override
    public int compareTo(Student s){
        //+ve --> current is greater
        //-ve ->o is greater
        return this.rollno-s.rollno;
    }

}
