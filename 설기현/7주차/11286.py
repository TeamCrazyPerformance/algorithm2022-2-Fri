import sys
class Heap:
	def __init__(self):
		self.arr = []

	def heapify_down(self, k, n):   
		while 2*k+1 < n:    # 위에서 아래로 내려감. 
			L, R = 2*k+1, 2*k+2   # 왼쪽 자식노드, 오른쪽 자식노드. 
			if L < n and abs(self.arr[L]) < abs(self.arr[k]): m = L    # 절댓값
			else: m = k
			if R < n and abs(self.arr[R]) < abs(self.arr[m]): m = R    # 자식노드 값이 더 작은 경우
			if m != k:
				self.arr[k], self.arr[m] = self.arr[m], self.arr[k]        # 위 아래 위치 변경. 
				k = m
			else: break

	def heapify_up(self, k):
		while  abs(self.arr[(k-1)//2]) >= abs(self.arr[k]) and (self.arr[(k-1)//2]) > (self.arr[k]):                 #절댓값
            
                # self.arr[(k-1)//2], self.arr[k] = self.arr[k], self.arr[(k-1)//2]          # 윗값이 아래 값보다 크면 둘을 뒤바꿈. 
                # k = (k-1)//2                                                               # k값 갱신. 
        


	def insert(self, key):                    # 삽입
		self.arr.append(key)
		self.heapify_up(len(self.arr)-1)      # 가장 마지막 자리 
        

	def delete_min(self):                   # 삭제 
		if len(self.arr) == 0: return "0"   # 배열의 원소가 존재하지 않는 경우(정상 종료와 구분하기 위해)
		self.arr[0], self.arr[-1] = self.arr[-1], self.arr[0]  # 배열의 원소가 존재하는 경우 가장 작은 값을 맨 뒤로 옮겨 pop()출력되게 만듦. 
		key = self.arr.pop()                                   # 맨 뒷 원소 출력. 
		self.heapify_down(0, len(self.arr))                    # arr[0]에 가장 큰 값이 들어가 있는 상황에서 이를 heapify_down 시켜줘야 함. 
		return str(key)                                        # 가장 작은 값 반환 

N = int(sys.stdin.readline())
heap = Heap()                                 # 객체 생성 
output = []
for i in range(N):
	T = int(sys.stdin.readline())             
	if T: heap.insert(T)                      # T가 0이 아닐때. 
	else: output.append(heap.delete_min())   
print("\n".join(output))                      # str 변환 
