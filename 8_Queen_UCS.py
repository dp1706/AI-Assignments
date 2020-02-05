class Board:
    def __init__(self,N):
        self.arr = [ N*[0] for i in range(N)]
        self.row = 0
        self.column = 0
        self.next = None

def print_table(board):
    for i in range(len(board.arr)):
        for j in range(len(board.arr[0])):
            print(board.arr[i][j], end=' ')
        print()

def valid(board):
    ''' Returns True if the position of queen is non-conflicting with others else False'''
    
    for i in range(0,board.row):
        if board.arr[i][board.column] == 1:
            return False
    
    for i,j in zip(range(board.row-1,-1,-1), range(board.column-1,-1,-1)):
        if board.arr[i][j] == 1:
            return False
    
    for i,j in zip(range(board.row+1,8), range(board.column+1,8)):
        if board.arr[i][j] == 1:
            return False
        
    for i,j in zip(range(board.row+1,8), range(board.column-1,-1,-1)):
        if board.arr[i][j] == 1:
            return False
        
    for i,j in zip(range(board.row-1,-1,-1), range(board.column+1,8)):
        if board.arr[i][j] == 1:
            return False
    
    return True

def Queen(original_board):
    last = Board(8)
    t = 1
    while(original_board.row < 8):
        for i in range(8):
            copy_board = Board(8)
            for j in range(8):
                for k in range(8):
                    copy_board.arr[j][k] = original_board.arr[j][k]
            
            copy_board.row = original_board.row + 1
            copy_board.column = i
            copy_board.arr[copy_board.row][i] = 1

            if t==1 and valid(copy_board):
                original_board.next = copy_board
                last = copy_board
                last.next = None
                t = 0
                
            elif valid(copy_board):
                last.next = copy_board
                last = copy_board
                last.next = None
            #print_table(b)

        if original_board.next != None:
            original_board = original_board.next
            #print(a.row)
            
        if original_board.row == 7:
            print("######### Final Board ##########")
            print_table(original_board)
            print("################################")
            return


if __name__ == "__main__":
    a = Board(8)
    print("######## Initial Board #########")
    print_table(a)
    print("################################\n")
    a.row = -1
    a.next = None
    Queen(a)

