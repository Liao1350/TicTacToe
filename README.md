## 程式簡介
簡單的N\*N井字棋遊戲，首先連成N顆棋子的人獲得勝利。目前只有真人對戰，可以自訂棋盤大小，並有重新開始的功能，也有加上簡單的防呆機制。

## 程式原理
- 檢查勝利函式

當一顆棋子被放下時，檢查該棋子的「米」字範圍內是否有N顆相連的棋子，如果有則回傳True，並將贏家設為放置的人，都沒有則False。

![image](https://user-images.githubusercontent.com/124888991/219394442-699d9a15-2703-4e42-a2ba-c4e737ed01c4.png)

- 更新棋盤資訊函式

將該玩家輸入的座標格子換成「O」或「X」，並輪替玩家順序。

![image](https://user-images.githubusercontent.com/124888991/219395016-78dc248d-3754-4507-9c6b-cadd10e92d39.png)

- 繪製棋盤函式

繪製出可較輕易閱讀的棋盤。

![image](https://user-images.githubusercontent.com/124888991/219395462-020bbe1c-44c8-4b4e-8496-e4c1ee75a79a.png)

- 隨機先後手

利用系統時間做為random的seed，並隨機選取0和1兩數之中的某一數，抽到的就是先手。
![image](https://user-images.githubusercontent.com/124888991/219398815-693a5292-aed5-448f-b5ee-f521e6cae441.png)

- 平手判定

在main裡放置計數器，當計數器數到與棋盤格數相同時則表示平手。
![image](https://user-images.githubusercontent.com/124888991/219402701-24be608d-e6d2-41ea-b6fd-6c2f7a6b9b8e.png)

## 程式演示
- 自訂棋盤大小

![image](https://user-images.githubusercontent.com/124888991/219397601-1e1f7b07-9dff-4f89-8309-b5dd719e6c79.png)

- 玩家輸入和獲勝

![image](https://user-images.githubusercontent.com/124888991/219399045-9a115b3a-4b69-485a-bc7e-690b918c6e24.png)

- 重新開始遊戲

![image](https://user-images.githubusercontent.com/124888991/219400200-5a497add-22a3-49b9-a431-688f742dd5d7.png)

- 平手

![image](https://user-images.githubusercontent.com/124888991/219403271-22f64b52-3592-4b75-8b4b-a04ea221100a.png)

- 防呆

![image](https://user-images.githubusercontent.com/124888991/219403818-66b5866c-7ecd-4935-8283-d7a8ab8869ed.png)
