public class People {
    private Integer id;
    //因为�?一�?圈子那么人就有左右两�?属性，而且左右也都�?人，所以明�?定义其类�?
    private People left;
    private People right;
 
    public People(Integer i) {
        this.id = i + 1;
    }
 
    public Integer getId() {
        return id;
    }
 
    public void setId(Integer id) {
        this.id = id;
    }
 
    public People getLeft() {
        return left;
    }
 
    public void setLeft(People left) {
        this.left = left;
    }
 
    public People getRight() {
        return right;
    }
 
    public void setRight(People right) {
        this.right = right;
    }
}
public class Circle {
    private int total = 0;
    private People first = null;
    private People last = null;
 
    /**
     * 向环里添加人，将新人添加到链表的尾部
     *
     * @param newPeople 新加入都�?
     */
    public void addPeople(People newPeople) {
        if (total <= 0) {
            //如果总数小于或等于零，�?�明这是�?里一�?人都没有，这�?添加后�??一�?和最后一�?都是�?�?
            first = newPeople;
            last = newPeople;
            //此时这个人都的左边和右边也都�?�?�?
            newPeople.setLeft(newPeople);
            newPeople.setRight(newPeople);
        } else {
            //如果�?里有人，则将新人加入到尾�?，因为是尾部，所以操作的就是first和last
            last.setRight(newPeople);//将原先最后一�?人的右边变为新人
            newPeople.setLeft(last);//将新人的左边设为原最后一�?人也就是现在的倒数�?二人
            newPeople.setRight(first);//将�?�人的右边�?�为�?一�?�?
            first.setLeft(newPeople);//将�??一人的左边变为新人
            last = newPeople;//将最有一�?人�?�为新人
        }
        total++;
    }
 
    /**
     * 删除�?淘汰的人
     *
     * @param deletePeople 需要删除的�?
     */
    public void deletePeople(People deletePeople) {
        if (total <= 0) {
            return;
        } else if (total == 1) {
            //如果�?�?�?有一�?人，那么游戏结束，�?�尾都�?�为null
            first = null;
            last = null;
        } else {
            //�?�?的人大于一�?，是开始删除操�?
            if (deletePeople == first) {
                first = deletePeople.getRight(); //如果�?�?一�?人，那么他右边都人就变成�?一�?
            } else if (deletePeople == last) {
                last = deletePeople.getLeft();   //相反，�?�果�?最后一�?人，那么他左边边都人就变成最后一�?
            }
 
            //将删除的人左边的人的右边设为删除的人的右边的人，�?不是有点儿绕，举�?例子�?
            //234，我�?要删�?3，那么将2的左边�?�为4�?
            deletePeople.getLeft().setRight(deletePeople.getRight());
            //同理，将删除的人右边的人的左边�?�为删除人的左边的人�?
            deletePeople.getRight().setLeft(deletePeople.getLeft());
        }
        total--;
    }
 
    public int getTotal() {
        return total;
    }
 
    public void setTotal(int total) {
        this.total = total;
    }
 
    public People getFirst() {
        return first;
    }
 
    public void setFirst(People first) {
        this.first = first;
    }
 
    public People getLast() {
        return last;
    }
 
    public void setLast(People last) {
        this.last = last;
    }
}
    private static Circle compute(Integer total, Integer keyNumber){
        Circle circle = new Circle();
        for (int i = 0; i < total; i++) {
            People people = new People(i);
            circle.addPeople(people); //向环�?添加�?
        }
 
        Integer count = 0;//用来计数
        People people = circle.getFirst(); //先拿到�??一�?�?
        while (circle.getTotal() > 1) {
            count++;
            if (count.equals(keyNumber)) {
                count = 0;
                circle.deletePeople(people);
            }
            people = people.getRight();//一�?一�?往后报�?
        }
        return circle;
    }
    
   public static void main(String[] args) {
        int total = 10; //定义要添加的人数
        int keyNumber = 3; //数到3退�?
        Circle circle = compute(total, keyNumber);
        System.out.println(total + "�?人围成一圈数数，数到" + keyNumber + "的�??淘汰，最后剩下的�?�?" + circle.getFirst().getId() + "�?人�?");
    }