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

		bool equals(ThermalVariable thisEquals, ThermalVariable that){
			return thisEquals.setValue(that.getValue());
		}

		bool addEqual(ThermalVariable a, ThermalVariable b){
			return this->add(a, b, a);
		}
		bool subtractEqual(ThermalVariable a, ThermalVariable b){
			return this->subtract(a, b, a);
		}
		bool multiplyEqual(ThermalVariable a, ThermalVariable b){
			return this->multiply(a, b, a);
		}
		bool divideEqual(ThermalVariable a, ThermalVariable b){
			return this->divide(a, b, a);
		}
		bool xorEqual(ThermalVariable a, ThermalVariable b){
			return this->XOR(a, b, a);
		}
		bool orEqual(ThermalVariable a, ThermalVariable b){
			return this->OR(a, b, a);
		}
		bool andEqual(ThermalVariable a, ThermalVariable b){
			return this->AND(a, b, a);
		}
		bool shiftLeftEqual(ThermalVariable a, ThermalVariable b){
			return this->shiftLeft(a, b, a);
		}
		bool shiftRightEqual(ThermalVariable a, ThermalVariable b){
			return this->shiftRight(a, b, a);
		}
		bool modEqual(ThermalVariable a, ThermalVariable b){
			return this->mod(a, b, a);
		}


		bool mod(ThermalVariable a, ThermalVariable b, ThermalVariable out){
			switch(out.dataTypeToId()){
				case THERMAL_DATATYPE_INT:{
					int *varA = (int *)a.getValue();
					int *varB = (int *)b.getValue();
					int sum = (*varA) % (*varB);
					out.setValue((void *)&sum);
					break;
				}
				case THERMAL_DATATYPE_CHAR:{
					char *varA = (char *)a.getValue();
					char *varB = (char *)b.getValue();
					char sum = (*varA) % (*varB);
					out.setValue((void *)&sum);
					break;
				}
				case THERMAL_DATATYPE_UINT32:{
					uint32_t *varA = (uint32_t *)a.getValue();
					uint32_t *varB = (uint32_t *)b.getValue();
					uint32_t sum = (*varA) % (*varB);
					out.setValue((void *)&sum);
					break;
				}
				case THERMAL_DATATYPE_UINT64:{
					uint64_t *varA = (uint64_t *)a.getValue();
					uint64_t *varB = (uint64_t *)b.getValue();
					uint64_t sum = (*varA) % (*varB);
					out.setValue((void *)&sum);
					break;
				}
				case THERMAL_DATATYPE_LONG:{
					long *varA = (long *)a.getValue();
					long *varB = (long *)b.getValue();
					long sum = (*varA) % (*varB);
					out.setValue((void *)&sum);
					break;
				}
				case THERMAL_DATATYPE_LONGINT:{
					long int *varA = (long int *)a.getValue();
					long int *varB = (long int *)b.getValue();
					long int sum = (*varA) % (*varB);
					out.setValue((void *)&sum);
					break;
				}
				case THERMAL_DATATYPE_SIZE:{
					size_t *varA = (size_t *)a.getValue();
					size_t *varB = (size_t *)b.getValue();
					size_t sum = (*varA) % (*varB);
					out.setValue((void *)&sum);
					break;
				}
				case THERMAL_DATATYPE_FLOAT:{
					uint64_t *varA = (uint64_t *)a.getValue();
					uint64_t *varB = (uint64_t *)b.getValue();
					uint64_t sum = (*varA) % (*varB);
					out.setValue((void *)&sum);
					break;
				}
				case THERMAL_DATATYPE_DOUBLE:{
					uint64_t *varA = (uint64_t *)a.getValue();
					uint64_t *varB = (uint64_t *)b.getValue();
					uint64_t sum = (*varA) % (*varB);
					out.setValue((void *)&sum);
					break;
				}

			
			}
			return true;
		}


		bool shiftRight(ThermalVariable a, ThermalVariable b, ThermalVariable out){
			switch(out.dataTypeToId()){
				case THERMAL_DATATYPE_INT:{
					int *varA = (int *)a.getValue();
					int *varB = (int *)b.getValue();
					int sum = (*varA) >> (*varB);
					out.setValue((void *)&sum);
					break;
				}
				case THERMAL_DATATYPE_CHAR:{
					char *varA = (char *)a.getValue();
					char *varB = (char *)b.getValue();
					char sum = (*varA) >> (*varB);
					out.setValue((void *)&sum);
					break;
				}
				case THERMAL_DATATYPE_UINT32:{
					uint32_t *varA = (uint32_t *)a.getValue();
					uint32_t *varB = (uint32_t *)b.getValue();
					uint32_t sum = (*varA) >> (*varB);
					out.setValue((void *)&sum);
					break;
				}
				case THERMAL_DATATYPE_UINT64:{
					uint64_t *varA = (uint64_t *)a.getValue();
					uint64_t *varB = (uint64_t *)b.getValue();
					uint64_t sum = (*varA) >> (*varB);
					out.setValue((void *)&sum);
					break;
				}
				case THERMAL_DATATYPE_LONG:{
					long *varA = (long *)a.getValue();
					long *varB = (long *)b.getValue();
					long sum = (*varA) >> (*varB);
					out.setValue((void *)&sum);
					break;
				}
				case THERMAL_DATATYPE_LONGINT:{
					long int *varA = (long int *)a.getValue();
					long int *varB = (long int *)b.getValue();
					long int sum = (*varA) >> (*varB);
					out.setValue((void *)&sum);
					break;
				}
				case THERMAL_DATATYPE_SIZE:{
					size_t *varA = (size_t *)a.getValue();
					size_t *varB = (size_t *)b.getValue();
					size_t sum = (*varA) >> (*varB);
					out.setValue((void *)&sum);
					break;
				}
				case THERMAL_DATATYPE_FLOAT:{
					uint64_t *varA = (uint64_t *)a.getValue();
					uint64_t *varB = (uint64_t *)b.getValue();
					uint64_t sum = (*varA) >> (*varB);
					out.setValue((void *)&sum);
					break;
				}
				case THERMAL_DATATYPE_DOUBLE:{
					uint64_t *varA = (uint64_t *)a.getValue();
					uint64_t *varB = (uint64_t *)b.getValue();
					uint64_t sum = (*varA) >> (*varB);
					out.setValue((void *)&sum);
					break;
				}

			
			}
			return true;
		}


		bool shiftLeft(ThermalVariable a, ThermalVariable b, ThermalVariable out){
			switch(out.dataTypeToId()){
				case THERMAL_DATATYPE_INT:{
					int *varA = (int *)a.getValue();
					int *varB = (int *)b.getValue();
					int sum = (*varA) << (*varB);
					out.setValue((void *)&sum);
					break;
				}
				case THERMAL_DATATYPE_CHAR:{
					char *varA = (char *)a.getValue();
					char *varB = (char *)b.getValue();
					char sum = (*varA) << (*varB);
					out.setValue((void *)&sum);
					break;
				}
				case THERMAL_DATATYPE_UINT32:{
					uint32_t *varA = (uint32_t *)a.getValue();
					uint32_t *varB = (uint32_t *)b.getValue();
					uint32_t sum = (*varA) << (*varB);
					out.setValue((void *)&sum);
					break;
				}
				case THERMAL_DATATYPE_UINT64:{
					uint64_t *varA = (uint64_t *)a.getValue();
					uint64_t *varB = (uint64_t *)b.getValue();
					uint64_t sum = (*varA) << (*varB);
					out.setValue((void *)&sum);
					break;
				}
				case THERMAL_DATATYPE_LONG:{
					long *varA = (long *)a.getValue();
					long *varB = (long *)b.getValue();
					long sum = (*varA) << (*varB);
					out.setValue((void *)&sum);
					break;
				}
				case THERMAL_DATATYPE_LONGINT:{
					long int *varA = (long int *)a.getValue();
					long int *varB = (long int *)b.getValue();
					long int sum = (*varA) << (*varB);
					out.setValue((void *)&sum);
					break;
				}
				case THERMAL_DATATYPE_SIZE:{
					size_t *varA = (size_t *)a.getValue();
					size_t *varB = (size_t *)b.getValue();
					size_t sum = (*varA) << (*varB);
					out.setValue((void *)&sum);
					break;
				}
				case THERMAL_DATATYPE_FLOAT:{
					uint64_t *varA = (uint64_t *)a.getValue();
					uint64_t *varB = (uint64_t *)b.getValue();
					uint64_t sum = (*varA) << (*varB);
					out.setValue((void *)&sum);
					break;
				}
				case THERMAL_DATATYPE_DOUBLE:{
					uint64_t *varA = (uint64_t *)a.getValue();
					uint64_t *varB = (uint64_t *)b.getValue();
					uint64_t sum = (*varA) << (*varB);
					out.setValue((void *)&sum);
					break;
				}

			
			}
			return true;
		}


		bool AND(ThermalVariable a, ThermalVariable b, ThermalVariable out){
			switch(out.dataTypeToId()){
				case THERMAL_DATATYPE_INT:{
					int *varA = (int *)a.getValue();
					int *varB = (int *)b.getValue();
					int sum = (*varA) & (*varB);
					out.setValue((void *)&sum);
					break;
				}
				case THERMAL_DATATYPE_CHAR:{
					char *varA = (char *)a.getValue();
					char *varB = (char *)b.getValue();
					char sum = (*varA) & (*varB);
					out.setValue((void *)&sum);
					break;
				}
				case THERMAL_DATATYPE_UINT32:{
					uint32_t *varA = (uint32_t *)a.getValue();
					uint32_t *varB = (uint32_t *)b.getValue();
					uint32_t sum = (*varA) & (*varB);
					out.setValue((void *)&sum);
					break;
				}
				case THERMAL_DATATYPE_UINT64:{
					uint64_t *varA = (uint64_t *)a.getValue();
					uint64_t *varB = (uint64_t *)b.getValue();
					uint64_t sum = (*varA) & (*varB);
					out.setValue((void *)&sum);
					break;
				}
				case THERMAL_DATATYPE_LONG:{
					long *varA = (long *)a.getValue();
					long *varB = (long *)b.getValue();
					long sum = (*varA) & (*varB);
					out.setValue((void *)&sum);
					break;
				}
				case THERMAL_DATATYPE_LONGINT:{
					long int *varA = (long int *)a.getValue();
					long int *varB = (long int *)b.getValue();
					long int sum = (*varA) & (*varB);
					out.setValue((void *)&sum);
					break;
				}
				case THERMAL_DATATYPE_SIZE:{
					size_t *varA = (size_t *)a.getValue();
					size_t *varB = (size_t *)b.getValue();
					size_t sum = (*varA) & (*varB);
					out.setValue((void *)&sum);
					break;
				}
				case THERMAL_DATATYPE_FLOAT:{
					uint64_t *varA = (uint64_t *)a.getValue();
					uint64_t *varB = (uint64_t *)b.getValue();
					uint64_t sum = (*varA) & (*varB);
					out.setValue((void *)&sum);
					break;
				}
				case THERMAL_DATATYPE_DOUBLE:{
					uint64_t *varA = (uint64_t *)a.getValue();
					uint64_t *varB = (uint64_t *)b.getValue();
					uint64_t sum = (*varA) & (*varB);
					out.setValue((void *)&sum);
					break;
				}

			
			}
			return true;
		}

		
		bool OR(ThermalVariable a, ThermalVariable b, ThermalVariable out){
			switch(out.dataTypeToId()){
				case THERMAL_DATATYPE_INT:{
					int *varA = (int *)a.getValue();
					int *varB = (int *)b.getValue();
					int sum = (*varA) | (*varB);
					out.setValue((void *)&sum);
					break;
				}
				case THERMAL_DATATYPE_CHAR:{
					char *varA = (char *)a.getValue();
					char *varB = (char *)b.getValue();
					char sum = (*varA) | (*varB);
					out.setValue((void *)&sum);
					break;
				}
				case THERMAL_DATATYPE_UINT32:{
					uint32_t *varA = (uint32_t *)a.getValue();
					uint32_t *varB = (uint32_t *)b.getValue();
					uint32_t sum = (*varA) | (*varB);
					out.setValue((void *)&sum);
					break;
				}
				case THERMAL_DATATYPE_UINT64:{
					uint64_t *varA = (uint64_t *)a.getValue();
					uint64_t *varB = (uint64_t *)b.getValue();
					uint64_t sum = (*varA) | (*varB);
					out.setValue((void *)&sum);
					break;
				}
				case THERMAL_DATATYPE_LONG:{
					long *varA = (long *)a.getValue();
					long *varB = (long *)b.getValue();
					long sum = (*varA) | (*varB);
					out.setValue((void *)&sum);
					break;
				}
				case THERMAL_DATATYPE_LONGINT:{
					long int *varA = (long int *)a.getValue();
					long int *varB = (long int *)b.getValue();
					long int sum = (*varA) | (*varB);
					out.setValue((void *)&sum);
					break;
				}
				case THERMAL_DATATYPE_SIZE:{
					size_t *varA = (size_t *)a.getValue();
					size_t *varB = (size_t *)b.getValue();
					size_t sum = (*varA) | (*varB);
					out.setValue((void *)&sum);
					break;
				}
				case THERMAL_DATATYPE_FLOAT:{
					uint64_t *varA = (uint64_t *)a.getValue();
					uint64_t *varB = (uint64_t *)b.getValue();
					uint64_t sum = (*varA) | (*varB);
					out.setValue((void *)&sum);
					break;
				}
				case THERMAL_DATATYPE_DOUBLE:{
					uint64_t *varA = (uint64_t *)a.getValue();
					uint64_t *varB = (uint64_t *)b.getValue();
					uint64_t sum = (*varA) | (*varB);
					out.setValue((void *)&sum);
					break;
				}

			
			}
			return true;
		}

		bool XOR(ThermalVariable a, ThermalVariable b, ThermalVariable out){
			switch(out.dataTypeToId()){
				case THERMAL_DATATYPE_INT:{
					int *varA = (int *)a.getValue();
					int *varB = (int *)b.getValue();
					int sum = (*varA) ^ (*varB);
					out.setValue((void *)&sum);
					break;
				}
				case THERMAL_DATATYPE_CHAR:{
					char *varA = (char *)a.getValue();
					char *varB = (char *)b.getValue();
					char sum = (*varA) ^ (*varB);
					out.setValue((void *)&sum);
					break;
				}
				case THERMAL_DATATYPE_UINT32:{
					uint32_t *varA = (uint32_t *)a.getValue();
					uint32_t *varB = (uint32_t *)b.getValue();
					uint32_t sum = (*varA) ^ (*varB);
					out.setValue((void *)&sum);
					break;
				}
				case THERMAL_DATATYPE_UINT64:{
					uint64_t *varA = (uint64_t *)a.getValue();
					uint64_t *varB = (uint64_t *)b.getValue();
					uint64_t sum = (*varA) ^ (*varB);
					out.setValue((void *)&sum);
					break;
				}
				case THERMAL_DATATYPE_LONG:{
					long *varA = (long *)a.getValue();
					long *varB = (long *)b.getValue();
					long sum = (*varA) ^ (*varB);
					out.setValue((void *)&sum);
					break;
				}
				case THERMAL_DATATYPE_LONGINT:{
					long int *varA = (long int *)a.getValue();
					long int *varB = (long int *)b.getValue();
					long int sum = (*varA) ^ (*varB);
					out.setValue((void *)&sum);
					break;
				}
				case THERMAL_DATATYPE_SIZE:{
					size_t *varA = (size_t *)a.getValue();
					size_t *varB = (size_t *)b.getValue();
					size_t sum = (*varA) ^ (*varB);
					out.setValue((void *)&sum);
					break;
				}
				case THERMAL_DATATYPE_FLOAT:{
					uint64_t *varA = (uint64_t *)a.getValue();
					uint64_t *varB = (uint64_t *)b.getValue();
					uint64_t sum = (*varA) ^ (*varB);
					out.setValue((void *)&sum);
					break;
				}
				case THERMAL_DATATYPE_DOUBLE:{
					uint64_t *varA = (uint64_t *)a.getValue();
					uint64_t *varB = (uint64_t *)b.getValue();
					uint64_t sum = (*varA) ^ (*varB);
					out.setValue((void *)&sum);
					break;
				}

			
			}
			return true;
		}

		bool divide(ThermalVariable a, ThermalVariable b, ThermalVariable out){
			switch(out.dataTypeToId()){
				case THERMAL_DATATYPE_INT:{
					int *varA = (int *)a.getValue();
					int *varB = (int *)b.getValue();
					int sum = (*varA) / (*varB);
					out.setValue((void *)&sum);
					break;
				}
				case THERMAL_DATATYPE_CHAR:{
					char *varA = (char *)a.getValue();
					char *varB = (char *)b.getValue();
					char sum = (*varA) / (*varB);
					out.setValue((void *)&sum);
					break;
				}
				case THERMAL_DATATYPE_UINT32:{
					uint32_t *varA = (uint32_t *)a.getValue();
					uint32_t *varB = (uint32_t *)b.getValue();
					uint32_t sum = (*varA) / (*varB);
					out.setValue((void *)&sum);
					break;
				}
				case THERMAL_DATATYPE_UINT64:{
					uint64_t *varA = (uint64_t *)a.getValue();
					uint64_t *varB = (uint64_t *)b.getValue();
					uint64_t sum = (*varA) / (*varB);
					out.setValue((void *)&sum);
					break;
				}
				case THERMAL_DATATYPE_LONG:{
					long *varA = (long *)a.getValue();
					long *varB = (long *)b.getValue();
					long sum = (*varA) / (*varB);
					out.setValue((void *)&sum);
					break;
				}
				case THERMAL_DATATYPE_LONGINT:{
					long int *varA = (long int *)a.getValue();
					long int *varB = (long int *)b.getValue();
					long int sum = (*varA) / (*varB);
					out.setValue((void *)&sum);
					break;
				}
				case THERMAL_DATATYPE_SIZE:{
					size_t *varA = (size_t *)a.getValue();
					size_t *varB = (size_t *)b.getValue();
					size_t sum = (*varA) / (*varB);
					out.setValue((void *)&sum);
					break;
				}
				case THERMAL_DATATYPE_FLOAT:{
					float *varA = (float *)a.getValue();
					float *varB = (float *)b.getValue();
					float sum = (*varA) / (*varB);
					out.setValue((void *)&sum);
					break;
				}
				case THERMAL_DATATYPE_DOUBLE:{
					double *varA = (double *)a.getValue();
					double *varB = (double *)b.getValue();
					double sum = (*varA) / (*varB);
					out.setValue((void *)&sum);
					break;
				}

			
			}
			return true;
		}

		bool multiply(ThermalVariable a, ThermalVariable b, ThermalVariable out){
			switch(out.dataTypeToId()){
				case THERMAL_DATATYPE_INT:{
					int *varA = (int *)a.getValue();
					int *varB = (int *)b.getValue();
					int sum = (*varA) * (*varB);
					out.setValue((void *)&sum);
					break;
				}
				case THERMAL_DATATYPE_CHAR:{
					char *varA = (char *)a.getValue();
					char *varB = (char *)b.getValue();
					char sum = (*varA) * (*varB);
					out.setValue((void *)&sum);
					break;
				}
				case THERMAL_DATATYPE_UINT32:{
					uint32_t *varA = (uint32_t *)a.getValue();
					uint32_t *varB = (uint32_t *)b.getValue();
					uint32_t sum = (*varA) * (*varB);
					out.setValue((void *)&sum);
					break;
				}
				case THERMAL_DATATYPE_UINT64:{
					uint64_t *varA = (uint64_t *)a.getValue();
					uint64_t *varB = (uint64_t *)b.getValue();
					uint64_t sum = (*varA) * (*varB);
					out.setValue((void *)&sum);
					break;
				}
				case THERMAL_DATATYPE_LONG:{
					long *varA = (long *)a.getValue();
					long *varB = (long *)b.getValue();
					long sum = (*varA) * (*varB);
					out.setValue((void *)&sum);
					break;
				}
				case THERMAL_DATATYPE_LONGINT:{
					long int *varA = (long int *)a.getValue();
					long int *varB = (long int *)b.getValue();
					long int sum = (*varA) * (*varB);
					out.setValue((void *)&sum);
					break;
				}
				case THERMAL_DATATYPE_SIZE:{
					size_t *varA = (size_t *)a.getValue();
					size_t *varB = (size_t *)b.getValue();
					size_t sum = (*varA) * (*varB);
					out.setValue((void *)&sum);
					break;
				}
				case THERMAL_DATATYPE_FLOAT:{
					float *varA = (float *)a.getValue();
					float *varB = (float *)b.getValue();
					float sum = (*varA) * (*varB);
					out.setValue((void *)&sum);
					break;
				}
				case THERMAL_DATATYPE_DOUBLE:{
					double *varA = (double *)a.getValue();
					double *varB = (double *)b.getValue();
					double sum = (*varA) * (*varB);
					out.setValue((void *)&sum);
					break;
				}

			
			}
			return true;
		}


		bool subtract(ThermalVariable a, ThermalVariable b, ThermalVariable out){
			switch(out.dataTypeToId()){
				case THERMAL_DATATYPE_INT:{
					int *varA = (int *)a.getValue();
					int *varB = (int *)b.getValue();
					int sum = (*varA) - (*varB);
					out.setValue((void *)&sum);
					break;
				}
				case THERMAL_DATATYPE_CHAR:{
					char *varA = (char *)a.getValue();
					char *varB = (char *)b.getValue();
					char sum = (*varA) - (*varB);
					out.setValue((void *)&sum);
					break;
				}
				case THERMAL_DATATYPE_UINT32:{
					uint32_t *varA = (uint32_t *)a.getValue();
					uint32_t *varB = (uint32_t *)b.getValue();
					uint32_t sum = (*varA) - (*varB);
					out.setValue((void *)&sum);
					break;
				}
				case THERMAL_DATATYPE_UINT64:{
					uint64_t *varA = (uint64_t *)a.getValue();
					uint64_t *varB = (uint64_t *)b.getValue();
					uint64_t sum = (*varA) - (*varB);
					out.setValue((void *)&sum);
					break;
				}
				case THERMAL_DATATYPE_LONG:{
					long *varA = (long *)a.getValue();
					long *varB = (long *)b.getValue();
					long sum = (*varA) - (*varB);
					out.setValue((void *)&sum);
					break;
				}
				case THERMAL_DATATYPE_LONGINT:{
					long int *varA = (long int *)a.getValue();
					long int *varB = (long int *)b.getValue();
					long int sum = (*varA) - (*varB);
					out.setValue((void *)&sum);
					break;
				}
				case THERMAL_DATATYPE_SIZE:{
					size_t *varA = (size_t *)a.getValue();
					size_t *varB = (size_t *)b.getValue();
					size_t sum = (*varA) - (*varB);
					out.setValue((void *)&sum);
					break;
				}
				case THERMAL_DATATYPE_FLOAT:{
					float *varA = (float *)a.getValue();
					float *varB = (float *)b.getValue();
					float sum = (*varA) - (*varB);
					out.setValue((void *)&sum);
					break;
				}
				case THERMAL_DATATYPE_DOUBLE:{
					double *varA = (double *)a.getValue();
					double *varB = (double *)b.getValue();
					double sum = (*varA) - (*varB);
					out.setValue((void *)&sum);
					break;
				}

			
			}
			return true;
		}

		bool add(ThermalVariable a, ThermalVariable b, ThermalVariable out){
			switch(out.dataTypeToId()){
				case THERMAL_DATATYPE_INT:{
					int *varA = (int *)a.getValue();
					int *varB = (int *)b.getValue();
					int sum = (*varA) + (*varB);
					out.setValue((void *)&sum);
					break;
				}
				case THERMAL_DATATYPE_CHAR:{
					char *varA = (char *)a.getValue();
					char *varB = (char *)b.getValue();
					char sum = (*varA) + (*varB);
					out.setValue((void *)&sum);
					break;
				}
				case THERMAL_DATATYPE_UINT32:{
					uint32_t *varA = (uint32_t *)a.getValue();
					uint32_t *varB = (uint32_t *)b.getValue();
					uint32_t sum = (*varA) + (*varB);
					out.setValue((void *)&sum);
					break;
				}
				case THERMAL_DATATYPE_UINT64:{
					uint64_t *varA = (uint64_t *)a.getValue();
					uint64_t *varB = (uint64_t *)b.getValue();
					uint64_t sum = (*varA) + (*varB);
					out.setValue((void *)&sum);
					break;
				}
				case THERMAL_DATATYPE_LONG:{
					long *varA = (long *)a.getValue();
					long *varB = (long *)b.getValue();
					long sum = (*varA) + (*varB);
					out.setValue((void *)&sum);
					break;
				}
				case THERMAL_DATATYPE_LONGINT:{
					long int *varA = (long int *)a.getValue();
					long int *varB = (long int *)b.getValue();
					long int sum = (*varA) + (*varB);
					out.setValue((void *)&sum);
					break;
				}
				case THERMAL_DATATYPE_SIZE:{
					size_t *varA = (size_t *)a.getValue();
					size_t *varB = (size_t *)b.getValue();
					size_t sum = (*varA) + (*varB);
					out.setValue((void *)&sum);
					break;
				}
				case THERMAL_DATATYPE_FLOAT:{
					float *varA = (float *)a.getValue();
					float *varB = (float *)b.getValue();
					float sum = (*varA) + (*varB);
					out.setValue((void *)&sum);
					break;
				}
				case THERMAL_DATATYPE_DOUBLE:{
					double *varA = (double *)a.getValue();
					double *varB = (double *)b.getValue();
					double sum = (*varA) + (*varB);
					out.setValue((void *)&sum);
					break;
				}
			}
			return true;
		}

		ThermalOperation(){
			this->init();
		}

		~ThermalOperation(){

		}
};
