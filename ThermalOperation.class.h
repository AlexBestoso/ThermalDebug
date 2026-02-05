#define THERMAL_OPERATOR_INVALID -1
#define THERMAL_OPERATOR_EQUALS 0
#define THERMAL_OPERATOR_PLUS 1
#define THERMAL_OPERATOR_MINUS 2
#define THERMAL_OPERATOR_MULTIPLY 3
#define THERMAL_OPERATOR_DIVIDE 4
#define THERMAL_OPERATOR_XOR 5
#define THERMAL_OPERATOR_OR 6
#define THERMAL_OPERATOR_AND 7
#define THERMAL_OPERATOR_SHIFT_LEFT 8
#define THERMAL_OPERATOR_SHIFT_RIGHT 9
#define THERMAL_OPERATOR_MOD 10
#define THERMAL_OPERATOR_PLUS_EQUALS 11
#define THERMAL_OPERATOR_MINUS_EQUALS 12
#define THERMAL_OPERATOR_MULTIPLY_EQUALS 13
#define THERMAL_OPERATOR_DIVIDE_EQUALS 14
#define THERMAL_OPERATOR_XOR_EQUALS 15
#define THERMAL_OPERATOR_OR_EQUALS 16
#define THERMAL_OPERATOR_AND_EQUALS 17
#define THERMAL_OPERATOR_SHIFT_LEFT_EQUALS 18
#define THERMAL_OPERATOR_SHIFT_RIGHT_EQUALS 19
#define THERMAL_OPERATOR_MOD_EQUALS 20

class ThermalOperation{
	private:
		struct thermalOperation data;

	public:
		int stringToOperationIndex(std::string op){
			if(op == "=")
				return THERMAL_OPERATOR_EQUALS;
			if(op == "+")
				return THERMAL_OPERATOR_PLUS;
			if(op == "-")
				return THERMAL_OPERATOR_MINUS;
			if(op == "*")
				return THERMAL_OPERATOR_MULTIPLY;
			if(op == "/")
				return THERMAL_OPERATOR_DIVIDE;
			if(op == "^")
				return THERMAL_OPERATOR_XOR;
			if(op == "|")
				return THERMAL_OPERATOR_OR;
			if(op == "&")
				return THERMAL_OPERATOR_AND;
			if(op == "<<")
				return THERMAL_OPERATOR_SHIFT_LEFT;
			if(op == ">>")
				return THERMAL_OPERATOR_SHIFT_RIGHT;
			if(op == "%")
				return THERMAL_OPERATOR_MOD;
			if(op == "+=")
				return THERMAL_OPERATOR_PLUS_EQUALS;
			if(op == "-=")
				return THERMAL_OPERATOR_MINUS_EQUALS;
			if(op == "*=")
				return THERMAL_OPERATOR_MULTIPLY_EQUALS;
			if(op == "/=")
				return THERMAL_OPERATOR_DIVIDE_EQUALS;
			if(op == "^=")
				return THERMAL_OPERATOR_XOR_EQUALS;
			if(op == "|=")
				return THERMAL_OPERATOR_OR_EQUALS;
			if(op == "&=")
				return THERMAL_OPERATOR_AND_EQUALS;
			if(op == "<<=")
				return THERMAL_OPERATOR_SHIFT_LEFT_EQUALS;
			if(op == ">>=")
				return THERMAL_OPERATOR_SHIFT_RIGHT_EQUALS;
			if(op == "%=")
				return THERMAL_OPERATOR_MOD_EQUALS;

			return THERMAL_OPERATOR_INVALID;
		}
		void init(void){
			this->data.name = "";
			this->data.description = "";
			this->data.variableCount = 0;
			this->data.variables = NULL;

		}
		void reset(void){
			this->data.name = "";
			this->data.description = "";
			this->data.variableCount = 0;
			if(this->data.variables != NULL) delete[] this->data.variables;
			this->data.variables = NULL;
		}
		ThermalOperation(){
			this->init();
		}

		~ThermalOperation(){

		}
};
