# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        
        answer_list = ListNode()
        
        first_head = l1
        second_head = l2
        answer_head = answer_list
        
        # 덧셈 수행
        first_trigger = True
        while first_head != None and second_head != None:
            if first_trigger:
                answer_head.val = first_head.val + second_head.val
                first_trigger = False
            else:
                now_node = ListNode(first_head.val + second_head.val)
                answer_head.next = now_node
                answer_head = answer_head.next
            first_head = first_head.next
            second_head = second_head.next
        
        # 나머지 자리수 붙이기
        if first_head != None:
            while first_head != None:
                now_node = ListNode(first_head.val)
                answer_head.next = now_node
                
                answer_head = answer_head.next
                first_head = first_head.next
            
        if second_head != None:
            while second_head != None:
                now_node = ListNode(second_head.val)
                answer_head.next = now_node
                
                answer_head = answer_head.next
                second_head = second_head.next
        
        # 자리수 연산
        answer_head = answer_list
        while answer_head != None:
            if answer_head.val >= 10:
                carriage = int(answer_head.val / 10)
                answer_head.val %= 10
                if answer_head.next != None:
                    answer_head.next.val += carriage
                else:
                    now_node = ListNode(carriage)
                    answer_head.next = now_node
            answer_head = answer_head.next
                    
        return answer_list
                
            

if __name__ == "__main__":
    l1 = ListNode(2)
    l1.next = ListNode(4)
    l1.next.next = ListNode(3)

    l2 = ListNode(5)
    l2.next = ListNode(6)
    l2.next.next = ListNode(4)

    s = Solution()
    answer_list = s.addTwoNumbers(l1, l2)
    while answer_list != None:
        print(answer_list.val)
        answer_list=answer_list.next