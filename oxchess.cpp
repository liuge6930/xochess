//#include <graphics.h>
//#include <iostream>
//#include <vector>
//#include <windows.h>
//// 读取操作
//// >>处理数据
////	>>绘制画面
////胜负条件：
////O/X任意一方连成三个即可获胜，这样的情况一共有8*2（棋子种类数）种
////但也也有平局情况
//
////粗暴的全局变量
//char current_Piece = 'O';//先手
//
//
//std::vector<std::vector<char>> board(3,
//	std::vector<char>(3, '-'));
//
////char board[3][3] = {
////	{'-','-','-'},
////	{'-','-','-'},
////	{'-','-','-'},
////};
//
//
//
////处理数据
//bool checkWin(char c) {
//	if (board[0][0] == c && board[0][1] == c && board[0][2] == c) return true;
//	if (board[1][0] == c && board[1][1] == c && board[1][2] == c) return true;
//	if (board[2][0] == c && board[2][1] == c && board[2][2] == c) return true;
//	if (board[0][0] == c && board[1][0] == c && board[2][0] == c) return true;
//	if (board[0][1] == c && board[1][1] == c && board[2][1] == c) return true;
//	if (board[0][2] == c && board[1][2] == c && board[2][2] == c) return true;
//	if (board[0][0] == c && board[1][1] == c && board[2][2] == c) return true;
//	if (board[0][2] == c && board[1][1] == c && board[2][0] == c) return true;
//	return false;
//}
//bool checkDraw() {
//	for (int i = 0;i < 3;++i) {
//		for (int j = 0;j < 3;++j) {
//			if (board[i][j] == '-')return false;
//		}
//	}
//	return true;
//}
//void drawBoard() {
//	line(0, 240, 720, 240);
//	line(0, 480, 720, 480);
//	line(240, 0, 240, 720);
//	line(480, 0, 480, 720);
//}
//void drawPiece() {
//	for (int i = 0;i < 3;++i) {
//		for (int j = 0;j < 3;++j) {
//			switch (board[i][j])
//			{
//			case'X':
//				
//				line(j * 240, i * 240, (j + 1) * 240, (i + 1) * 240);
//				line(j * 240, (i + 1) * 240, (j + 1) * 240, i * 240);
//				setlinecolor(WHITE);
//				break;
//			case'O':
//				circle(j * 240 + 120, i * 240 + 120, 100);
//				setlinecolor(WHITE);
//				break;
//			case '-':
//				break;
//			default:
//				break;
//			}
//		}
//	}
//
//}
//void drawTipText() {
//	static TCHAR str[64];
//	_stprintf_s(str, _T("当前棋子类型：%c"), current_Piece);
//	settextcolor(RGB(255, 255, 255));
//	outtextxy(0, 0, str);
//}
//
//int main() {
//	/*std::cout << "welcome to my xochess game\nbut this is NOT the game console\n" << std::endl;*/
//	initgraph(720, 720);
//	bool running = true;
//	ExMessage msg;
//
//	//主循环
//
//	BeginBatchDraw();
//	while (running) {
//		while (peekmessage(&msg)) {
//			if (msg.message == WM_LBUTTONDOWN) {
//				//计算点击位置
//				int x = msg.x;
//				int y = msg.y;
//
//				//精妙一步
//				int index_x = x / 240;//0,1,2
//				int index_y = y / 240;//0,1,2
//
//				//尝试落子
//				if (board[index_y][index_x] == '-') {
//					board[index_y][index_x] = current_Piece;
//					if (current_Piece == 'O'){
//						current_Piece = 'X';
//					}
//					else{
//						current_Piece = 'O';
//					}
//				}
//
//			}
//
//
//		}
//
//		if (checkWin('X')) {
//			MessageBox(GetHWnd(), _T("X获胜！"), _T("游戏结束！"), MB_OK);
//			running = false;
//		}
//		if (checkWin('O')) {
//			MessageBox(GetHWnd(), _T("O获胜！"), _T("游戏结束！"), MB_OK);
//			running = false;
//		}
//		if (checkDraw()) {
//			MessageBox(GetHWnd(), _T("平局！"), _T("游戏结束！"), MB_OK);
//			running = false;
//		}
//		//渲染画面
//		cleardevice();
//
//		drawBoard();
//		drawPiece();
//		drawTipText();
//
//		FlushBatchDraw();
//	}
//	EndBatchDraw();
//	//分配棋盘内存
//	
//}
//
//
//
//
//
//
//
//
//
///*char** board = (char**)malloc(sizeof(char*) * row);
//	for (int i = 0; i < row; ++i) {
//		board[i] = (char*)malloc(sizeof(char) * col);
//	}
//	for (int i = 0;i < row;++i) {
//		for (int j = 0;j < col;++j) {
//			board[i][j] = '-';
//		}
//	}*/
//	//毁灭吧！傻逼malloc，我去用vector更安全哈哈哈哈哈哈哈哈哈哈
//	/*for (int i = 0;i < row;++i) {
//		for (int j = 0;j < col;++j) {
//			std::cout << board[i][j] << std::endl;
//		}
//		std::cout << "\n" << std::endl;
//	}*/