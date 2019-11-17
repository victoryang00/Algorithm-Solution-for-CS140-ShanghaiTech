  class Element {
        int val;
        Element parent;

        public Element(int val) {
            this.val = val;
        }

        /**
         *
         * @return this所在集合的·代表·
         */
        Element find(){
            if(parent==null){
                return this;
            }else{
                return parent.find();
            }
        }


        /**
         * 如果this与element在不同的集合中,就将这两个集合合并
         * @param element 另一个元素
         */
        void union(Element element){
            Element myroot = this.find();
            Element yourroot = element.find();
            if(myroot!=yourroot){
                myroot.parent = yourroot;
            }
        }
    }