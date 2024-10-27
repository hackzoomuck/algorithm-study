package Med;

// 3
 class ListNode {
      int val;
      ListNode next;
      ListNode() {}
      ListNode(int val) { this.val = val; }
      ListNode(int val, ListNode next) { this.val = val; this.next = next; }
  }

class AddTwoNumbers {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
      ListNode dummuy = new ListNode();
        ListNode result = new ListNode(0,dummuy);
        int carry = 0;
        while(l1 != null || l2 != null || carry != 0) {
            int total = carry;
            if(l1 != null) {
                total += l1.val;
                l1 = l1.next;
            }
            if(l2 != null) {
                total += l2.val;
                l2 = l2.next;
            }
            carry = total/10;
            ListNode resultNode = new ListNode(total%10);
            dummuy.next = resultNode;
            dummuy = dummuy.next;
        }
                
        return result.next.next ;
    }
}