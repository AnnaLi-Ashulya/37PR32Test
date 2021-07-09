#include "Order.h"
#include "KFC.h"

int Order::amount = 0;

int main() {
	/*Order a(Date(), Time(), "Pizza", 20, 200);
	Order b(Date(), Time(), "Burger", 10, 100);
	Order c(Date(), Time(), "Cofe", 15, 70);

	cout << a << b << c<<"\n";*/

	KFC one;
	char line[100];
	int minutes = 0;
	float price = 0;
	int menu = 0;
	do {
		cout << "1' Create order\n" <<
			"2' Show table of orders" << "\n"
			<< "3' Take order\n";
		cin >> menu;
		switch (menu)
		{
		case 1:
			cout << "Input description ";
			cin.get();
			cin.getline(line, 100);
			cout << "Input ready minutes ";
			cin >> minutes;
			cout << "Input price ";
			cin >> price;
			one.addOrder(Order(Date(), Time(), line, 
				minutes, price));
			break;
		case 2:
			one.showTable();
			break;
		case 3:
			one.takeOrder();
			break;
		default:
			break;
		}
	} while (menu != 0);

	return 0;
}