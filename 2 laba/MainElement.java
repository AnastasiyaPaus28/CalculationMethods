package gausMainElement;

public class MainElement {

	private double Array[][];
	private double X[] = new double[3];

	public static void main(String[] args) {
		
		MainElement mainElement = new MainElement();
		System.out.println("Массив:");
		mainElement.outputArray();
		mainElement.calculation();
		mainElement.findingArrayX();
		System.out.println("Полученный массив:");
		mainElement.outputArray();
		System.out.println("Корни уравнения: ");
		mainElement.outputArrayX();
	}

	MainElement() {
		double temporaryArray[][] = {{0.13, -0.14, -2, 0.15},
                {0.75, 0.18, -0.77, 0.11},
                {0.28, -0.17, 0.39, 0.12}};
		Array = temporaryArray;
	}

	public void calculation() {
		//int N = 3;
		//int M = 4;

		int maxn; // индекс максимального элемента столбца
		double max; // максимальный элемент
		double buff;
		double p;
		// поиск максимального
		for (int j = 0; j < 3; j++) {
			max = Math.abs(Array[j][j]);
			maxn = j;
			for (int i = j; i < 3; i++) {
				if (max < Math.abs(Array[i][j])) {
					max = Array[i][j];
					maxn = i;
				}
			}
			// перестановка
			for (int k = j; k < 3; k++) {
				buff = Array[j][k];
				Array[j][k] = Array[maxn][k];
				Array[maxn][k] = buff;
			}
			// этап метода Гаусса
			for (int t = j + 1; t < 4; t++) {
				Array[j][t] /= Array[j][j];
			}
			Array[j][j] = 1;
			for (int i = j + 1; i < 3; i++) {
				p = Array[i][j];
				for (int k = j; k < 4; k++) {
					Array[i][k] -= (Array[j][k] * p);
				}
			}
		}
		Array[2][3] /= Array[2][2];
		Array[2][2] = 1;

	}
	
	void outputArray()
	{
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 4; j++) {
				System.out.print((Math.round(Array[i][j] * 1000.0) / 1000.0) + "   ");
			}
			System.out.println();
		}
	}
	
	void findingArrayX() {
		
		X[2] = Array[2][3];
		X[2] = Math.round(X[2] * 1000.0) / 1000.0;
		for (int i = 1; i >= 0; i--) {
			X[i] = Array[i][3];
			for (int j = 2; j >= i + 1; j--) {
				X[i] -= Array[i][j] * X[j];
			}
			X[i] = Math.round(X[i] * 1000.0) / 1000.0;
		}
	}
	
	void outputArrayX(){
		for (int i = 0; i < 3; i++) {
			System.out.println("X" + (i + 1) + ": " + X[i]);
		}
	}
}
