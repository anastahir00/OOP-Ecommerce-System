#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
using namespace std;
const int MAX_PRODUCTS = 100;
const int MAX_CART_ITEMS = 50;
class Product //encapsulation, operator overloading, static member used in this class
{
	private:
    	int id;
    	string name;
    	string category;
    	double price;
    	int stock;
	public:
    	static int totalProducts; //static member
    	Product() : id(0), name(""), category(""), price(0.0), stock(0)
		{
        	totalProducts++;
    	}

    	Product(int id, string name, string category, double price, int stock)
        	: id(id), name(name), category(category), price(price), stock(stock)
		{
        	totalProducts++;
    	}
	    ~Product()
		{
    	    totalProducts--;
    	}
    	//Operator overloaded + friend concepy ider use kya
    	//<< operator ko overload kya
	    friend ostream& operator<<(ostream& os, const Product& product)
		{
    	    os << product.id << " - " << product.name << " - " << product.category
        	<< " - $" << product.price << " - " << product.stock;
        	return os;
    	}
    	//Getters starts from here
    	int getId() const
		{
			return id;
		}
    	string getName() const 
		{
			return name; 
		}
    	string getCategory() const
		{
			return category;
		}
    	double getPrice() const 
		{
			return price;
		}
    	int getStock() const
		{
			return stock;
		}
		//setter from here
	    void setStock(int newStock)
		{
			stock = newStock;
		}
};
int Product::totalProducts = 0; //static member ko initialize
class UserManager //Class, user ko register or login ke lye 
{
	public:
	    void registerUser()
		{
	        string username, password;
	        cout << "Enter username: ";
        	cin >> username;
        	cout << "Enter password: ";
        	cin >> password;
        	ifstream infile("users.txt"); //check kre ga k user exist krta ya ni
        	string existingUser, existingPass;
        	while (infile >> existingUser >> existingPass)
			{
            	if (existingUser == username)
				{
            	    cout << "Username already exists. Please try a different username.\n";
            	    infile.close();
            	    return;
            	}
        	}
        	infile.close();
        	ofstream file("users.txt", ios::app);
        	file << username << " " << password << endl;
        	file.close();
        	cout << "User registered successfully!\n";
    	}
    	bool loginUser()
		{
        	string username, password;
        	cout << "Enter username: ";
        	cin >> username;
        	cout << "Enter password: ";
        	cin >> password;
        	ifstream file("users.txt");
        	string fileUser, filePass;
        	while (file >> fileUser >> filePass)
			{
        	    if (fileUser == username && filePass == password)
				{
            	    cout << "Login successful!\n";
                return true;
            	}
        	}
        	cout << "Invalid username or password.\n";
        	return false;
    	}
};
class EcommerceSystem //Base class, handly products
{
	protected:
	    Product products[MAX_PRODUCTS];
	    int productCount;
    	void loadProducts()
		{
        	ifstream file("products.txt");
        	if (!file)
			{
        	    createDefaultProducts();
        	    return;
        	}
        	productCount = 0;
        	while (productCount < MAX_PRODUCTS && !file.eof())
			{
        	    int id, stock;
        	    string name, category;
        	    double price;
        	    file >> id;
        	    if (file.eof()) break;
        	    file.get(); //new line consume kr le ga
            	getline(file, name, ',');
            	getline(file, category, ',');
            	file >> price >> stock;
            	file.ignore();
            products[productCount++] = Product(id, name, category, price, stock);
        }
        file.close();
    }

    	void saveProducts()
		{
    	    ofstream file("products.txt");
    	    if (!file)
			{
    	        throw runtime_error("Unable to open file for saving products.");
    	    }
    	    for (int i = 0; i < productCount; i++)
			{
    	        file << products[i].getId() << " " << products[i].getName() << ","
    	             << products[i].getCategory() << "," << products[i].getPrice()
    	             << " " << products[i].getStock() << endl;
    	    }
    	    file.close();
    	}
    	void createDefaultProducts()
		{
    	    productCount = 25;
    	    products[0] = Product(1, "Gaming Laptop", "Tech and Games", 1200.00, 10);
    	    products[1] = Product(2, "Wireless Mouse", "Tech and Games", 25.00, 50);
    	    products[2] = Product(3, "Mechanical Keyboard", "Tech and Games", 75.00, 30);
    	    products[3] = Product(4, "4K Monitor", "Tech and Games", 350.00, 20);
    	    products[4] = Product(5, "VR Headset", "Tech and Games", 430.00, 5);
    	    products[5] = Product(6, "Fiction Novel", "Books", 15.99, 100);
    	    products[6] = Product(7, "History Book", "Books", 22.50, 60);
    	    products[7] = Product(8, "Cooking Guide", "Books", 18.00, 80);
    	    products[8] = Product(9, "Science Textbook", "Books", 45.00, 40);
    	    products[9] = Product(10, "Children's Storybook", "Books", 12.00, 70);
    	    products[10] = Product(11, "Office Chair", "Furniture", 150.00, 15);
    	    products[11] = Product(12, "Wooden Table", "Furniture", 300.00, 7);
    	    products[12] = Product(13, "Bookshelf", "Furniture", 85.00, 20);
    	    products[13] = Product(14, "Couch", "Furniture", 550.00, 3);
    	    products[14] = Product(15, "Bed Frame", "Furniture", 400.00, 6);
    	    products[15] = Product(16, "Lipstick Set", "Beauty Products", 29.99, 40);
    	    products[16] = Product(17, "Face Cream", "Beauty Products", 35.00, 25);
    	    products[17] = Product(18, "Shampoo", "Beauty Products", 12.00, 50);
    	    products[18] = Product(19, "Perfume", "Beauty Products", 60.00, 15);
    	    products[19] = Product(20, "Makeup Kit", "Beauty Products", 45.00, 30);
    	    products[20] = Product(21, "Organic Apples(1kg)", "Grocery", 4.50, 100);
    	    products[21] = Product(22, "Milk(1L)", "Grocery", 2.00, 100);
    	    products[22] = Product(23, "Brown Bread", "Grocery", 3.00, 80);
    	    products[23] = Product(24, "Rice(1kg)", "Grocery", 1.50, 90);
    	    products[24] = Product(25, "Eggs(12pcs)", "Grocery", 2.50, 75);
    	    saveProducts();
    	}
    	void displayAllProducts()
		{
    	    cout << "\nID - Name - Category - Price - Stock\n";
    	    for (int i = 0; i < productCount; i++)
			{
    	        cout << products[i] << endl;
    	    }
    	}
	public:
    	EcommerceSystem()
		{	//use exception handling concept
			//try code block section ko monitor kre ga k koi exception to ni
			//agr exception ho gi to control catch block ke paas chala jaye ga
    	    try
			{
    	        loadProducts();
    	    } catch (exception &e)
			{
    	        cout << "Error loading products: " << e.what() << endl;//e.what display error message
    	        productCount = 0;
    	    }
    	}
    	virtual ~EcommerceSystem() {} //virtual concept ider use hua

    int findProductIndexById(int id) {
        for (int i = 0; i < productCount; i++) {
            if (products[i].getId() == id) {
                return i;
            }
        }
        return -1;
    }
};
// Admin class inherits EcommerceSystem
class Admin : public EcommerceSystem
{
	private:
	    string salesLogFilename;
    	void viewSalesRecords()
		{
    	    ifstream file(salesLogFilename.c_str());
    	    if (!file)
			{
    	        cout << "No sales records found." << endl;
    	        return;
    	    }
    	    cout << "\nSales Records:\n";
    	    string line;
    	    while (getline(file, line))
			{
    	        cout << line << endl;
    	    }
    	    file.close();
    	}
    	void saveSale(const string &record)
		{
    	    ofstream file(salesLogFilename.c_str(), ios::app);
    	    file << record << endl;
    	    file.close();
    	}
	public:
	    Admin()
		{
	        salesLogFilename = "sales.txt";
	    }
    	void menu()
		{
    	    string password;
    	    cout << "Enter Admin Password: ";
    	    cin >> password;
    	    if (password != "admin123")
			{
    	        cout << "Incorrect password!" << endl;
    	        return;
    	    }
        	while (true) {
        	    cout << "\n--- Admin Menu ---\n"
        	         << "1. View Sales Records\n"
        	         << "2. Add Product\n"
        	         << "3. Remove Product\n"
        	         << "4. View Product Catalog\n"
        	         << "5. Logout\nChoose an option: ";
        	    int choice;
        	    cin >> choice;
	            if (choice == 1)
				{
    	            viewSalesRecords();
        	    }
            	else if (choice == 2)
				{
            	    if (productCount >= MAX_PRODUCTS)
					{
            	        cout << "Product list full, cannot add more." << endl;
            	        continue;
            	    }
            	    int id, stock;
            	    string name, category;
            	    double price;
            	    cout << "Enter product ID: ";
            	    cin >> id;
            	    cout << "Enter product name: ";
            	    cin.ignore();
            	    getline(cin, name);
            	    cout << "Enter product category: ";
            	    getline(cin, category);
            	    cout << "Enter product price: ";
            	    cin >> price;
            	    cout << "Enter stock quantity: ";
            	    cin >> stock;
            	    products[productCount++] = Product(id, name, category, price, stock);
            	    saveProducts();
            	    cout << "Product added successfully." << endl;
            	}
            else if (choice == 3)
			{
                int id;
                cout << "Enter product ID to remove: ";
                cin >> id;
                int index = findProductIndexById(id);
                if (index == -1)
				{
                    cout << "Product ID not found." << endl;
                }
                else
				{
                    for (int i = index; i < productCount - 1; i++)
					{
                        products[i] = products[i + 1];
                    }
                    productCount--;
                    saveProducts();
                    cout << "Product removed successfully." << endl;
                }
            }
            else if (choice == 4)
			{
                displayAllProducts();
            }
            else if (choice == 5)
			{
                cout << "Logging out from Admin..." << endl;
                break;
            }
            else
			{
                cout << "Invalid choice, try again." << endl;
            }
        }
    }
};
// Customer class inherits EcommerceSystem
class Customer : public EcommerceSystem
{
	private:
	    Product cart[MAX_CART_ITEMS];
	    int cartCount;	
    	void addToCart(int productId, int quantity)
		{
   	    	int productIndex = findProductIndexById(productId);
    	    if (productIndex == -1)
			{
    	        cout << "Product not found." << endl;
    	        return;
    	    }
    	    if (products[productIndex].getStock() < quantity)
			{
    	        cout << "Not enough stock." << endl;
    	        return;
    	    }
    	    if (cartCount >= MAX_CART_ITEMS)
			{
    	        cout << "Cart is full, cannot add more products." << endl;
    	        return;
    	    }
    	    // Reduce stock
    	    products[productIndex].setStock(products[productIndex].getStock() - quantity);
    	    saveProducts();	
        	// Check if already in cart
        	for (int i = 0; i < cartCount; i++)
			{
        	    if (cart[i].getId() == productId)
				{
        	        cart[i].setStock(cart[i].getStock() + quantity);
        	        cout << "Added " << quantity << " more to existing cart item." << endl;
        	        return;
        	    }
        	}
        	// Add new item to cart
        	cart[cartCount++] = Product(productId, products[productIndex].getName(), products[productIndex].getCategory(), products[productIndex].getPrice(), quantity);
        	cout << "Added to cart." << endl;
    	}	
    	void viewCart()
		{
        	if (cartCount == 0)
			{
        	    cout << "Cart is empty." << endl;
        	    return;
        	}
        	cout << "\n--- Cart Contents ---\n";
        	cout << "Name - Price - Quantity - Total\n";
        	double totalAmount = 0;
        	for (int i = 0; i < cartCount; i++)
			{
        	    double total = cart[i].getPrice() * cart[i].getStock();
        	    totalAmount += total;
        	    cout << cart[i].getName() << " - $" << cart[i].getPrice() << " - " << cart[i].getStock() << " - $" << total << endl;
        	}
        	cout << "Total Amount: $" << totalAmount << endl;
    	}
    	void checkout()
		{
        	if (cartCount == 0)
			{
        	    cout << "Cart is empty. Add products before checkout." << endl;
        	    return;
        	}
        	viewCart();
        	cout << "Proceed to checkout? (y/n): ";
        	char ch;
        	cin >> ch;
        	if (ch != 'y' && ch != 'Y')
			{
        	    cout << "Checkout cancelled." << endl;
        	    return;
        	}
        	// Log sale (simple text without date/time)
        	ofstream file("sales.txt", ios::app);
        	file << "Sale: ";
        	for (int i = 0; i < cartCount; i++)
			{
        	    file << cart[i].getName() << " (Qty: " << cart[i].getStock() << "), ";
        	}
        	file << endl;
        	file.close();
        	cartCount = 0;
        	cout << "Checkout successful! Thank you for your purchase." << endl;
    	}
    	void selectCategory()
		{
       		cout << "\nSelect a Category:\n"
        	     << "1. Tech and Games\n"
        	     << "2. Books\n"
        	     << "3. Furniture\n"
        	     << "4. Beauty Products\n"
        	     << "5. Grocery\n"
        	     << "Your choice: ";
        	int choice;
        	cin >> choice;
        	string category;
        	switch (choice)
			{
        	    case 1: category = "Tech and Games"; break;
        	    case 2: category = "Books"; break;
        	    case 3: category = "Furniture"; break;
        	    case 4: category = "Beauty Products"; break;
        	    case 5: category = "Grocery"; break;
        	    default:
        	        cout << "Invalid category." << endl;
        	        return;
        	}
        	cout << "\nProducts in " << category << ":\n";
        	for (int i = 0; i < productCount; i++)
			{
        	    if (products[i].getCategory() == category)
				{
        	        cout << products[i] << endl;
        	    }
        	}
        	cout << "Enter product ID to add to cart: ";
        	int productId;
        	cin >> productId;
        	cout << "Enter quantity: ";
        	int quantity;
        	cin >> quantity;
        	addToCart(productId, quantity);
    	}
	public:
    	Customer() : cartCount(0) {}
    	void menu()
		{
        	while (true)
			{
        	    cout << "\n--- Customer Menu ---\n"
        	         << "1. Select Category and Add Products\n"
        	         << "2. View Cart\n"
        	         << "3. Checkout\n"
        	         << "4. Logout\n"
        	         << "Choose an option: ";
        	    int choice;
            	cin >> choice;
            	if (choice == 1)
				{
                	selectCategory();
            	}
            	else if (choice == 2)
				{
            	    viewCart();
            	}
            	else if (choice == 3)
				{
            	    checkout();
            	}
            	else if (choice == 4)
				{
            	    cout << "Logging out from Customer..." << endl;
            	    break;
            	}
            	else
				{
            	    cout << "Invalid choice, try again." << endl;
            	}
        	}
    	}
};
int main()
{
    UserManager userManager;
    cout << "Welcome to the E-commerce System!\n";
    cout << "Are you a:\n1. Admin\n2. Customer\nChoose 1 or 2: ";
    int role;
    cin >> role;
    if (role == 1) {
        Admin admin;
        admin.menu();
    }
    else if (role == 2)
	{
        // Customer registration and login menu
        while (true)
		{
            cout << "\nCustomer Portal:\n1. Register\n2. Login\n3. Exit\nChoose an option: ";
            int option;
            cin >> option;
            if (option == 1)
			{
                userManager.registerUser();
            }
            else if (option == 2)
			{
                if (userManager.loginUser())
				{
                    Customer customer;
                    customer.menu();
                    break;
                }
            }
            else if (option == 3)
			{
                cout << "Exiting Customer Portal.\n";
                break;
            }
            else
			{
                cout << "Invalid option. Try again.\n";
            }
        }
    }
    else
	{
        cout << "Invalid choice. Exiting." << endl;
    }
    return 0;
}
