#define THERMAL_DATATYPE_UNKNOWN -1
#define THERMAL_DATATYPE_INT 0
#define THERMAL_DATATYPE_CHAR 1
#define THERMAL_DATATYPE_UINT32 2
#define THERMAL_DATATYPE_UINT64 3
#define THERMAL_DATATYPE_LONG 5
#define THERMAL_DATATYPE_LONGINT 6
#define THERMAL_DATATYPE_SIZE 7
#define THERMAL_DATATYPE_FLOAT 8
#define THERMAL_DATATYPE_DOUBLE 9
class ThermalVariable{
	private:
		std::string name;
		std::string dataType;
		void *value;

	public:

		ThermalVariable(){
			this->name = "";
			this->dataType = "";
			this->value = NULL;
		}
		
		~ThermalVariable(){

		}
		
		int dataTypeToId(void){
			if(this->dataType == "int")
				return THERMAL_DATATYPE_INT;
			if(this->dataType == "char")
				return THERMAL_DATATYPE_CHAR;
			if(this->dataType == "uint32_t")
				return THERMAL_DATATYPE_UINT32;
			if(this->dataType == "uint64_t")
				return THERMAL_DATATYPE_UINT64;
			if(this->dataType == "long")
				return THERMAL_DATATYPE_LONG;
			if(this->dataType == "long int")
				return THERMAL_DATATYPE_LONGINT;
			if(this->dataType == "size_t")
				return THERMAL_DATATYPE_SIZE;
			if(this->dataType == "float")
				return THERMAL_DATATYPE_FLOAT;
			if(this->dataType == "double")
				return THERMAL_DATATYPE_DOUBLE;
			return THERMAL_DATATYPE_UNKNOWN;
		}


		void create(std::string t, std::string n, int *v){
			this->create(t, n, (void *)v);
		}
		void create(std::string t, std::string n, char *v){
			this->create(t, n, (void *)v);
		}
		void create(std::string t, std::string n, float *v){
			this->create(t, n, (void *)v);
		}
		void create(std::string t, std::string n, double *v){
			this->create(t, n, (void *)v);
		}
		//void create(std::string t, std::string n, size_t *v){
		//	this->create(t, n, (void *)v);
		//}
		void create(std::string t, std::string n, long *v){
			this->create(t, n, (void *)v);
		}
		void create(std::string t, std::string n, uint32_t *v){
			this->create(t, n, (void *)v);
		}
		void create(std::string t, std::string n, uint64_t *v){
			this->create(t, n, (void *)v);
		}
		void create(std::string t, std::string n, void *v){
			this->name = n;
			this->value = v;
			this->dataType = t;
		}

		std::string getName(void){
			return this->name;
		}
		std::string getDataType(void){
			return this->dataType;
		}
		int getDataTypeMacro(void){
			return this->dataTypeToId();
		}
		void *getValue(void){
			return this->value;
		}

		uint64_t getValueAutocast(void){
			uint64_t ret = 0;
			switch(this->dataTypeToId()){
				case THERMAL_DATATYPE_INT:{
					int value = this->getValueInt();
					ret = (uint64_t)value;
				}
				case THERMAL_DATATYPE_CHAR:{
					char value = this->getValueChar();
					ret = (uint64_t)value;
				}
				case THERMAL_DATATYPE_UINT32:{
					uint32_t value = this->getValueUint32();
					ret = (uint64_t)value;
				}
				case THERMAL_DATATYPE_UINT64:{
					ret = this->getValueUint64();
				}
				case THERMAL_DATATYPE_LONG:{
					long value = this->getValueLong();
					ret = (uint64_t)value;
				}
				case THERMAL_DATATYPE_LONGINT:{
					ret = this->getValueUint64();
				}
				case THERMAL_DATATYPE_SIZE:{
					ret = this->getValueUint64();
				}
				case THERMAL_DATATYPE_FLOAT:{
					float value = this->getValueFloat();
					ret = (uint64_t)value;
				}
				case THERMAL_DATATYPE_DOUBLE:{
					double value = this->getValueDouble();
					ret = (uint64_t)value;
				}
				default:{
					ret = this->getValueUint64();
				}
			}

			return ret;
		}

		/*\
		 *  Void will be type casted into whatever type the memory is 
		 *  automatically detected to be.
		* *   */
		bool setValue(void *val){
			if(this->value == NULL){
				return false;
			}
			switch(this->dataTypeToId()){
				case THERMAL_DATATYPE_INT:{
					int *memory = (int *)this->value;
					int *data = (int *)val;
					*memory = *data;
					return true;
				}
				case THERMAL_DATATYPE_CHAR:{
					char *memory = (char *)this->value;
					char *data = (char *)val;
					*memory = *data;
					return true;
				}
				case THERMAL_DATATYPE_UINT32:{
					uint32_t *memory = (uint32_t *)this->value;
					uint32_t *data = (uint32_t *)val;
					*memory = *data;
					return true;
				}
				case THERMAL_DATATYPE_UINT64:{
					uint64_t *memory = (uint64_t *)this->value;
					uint64_t *data = (uint64_t *)val;
					*memory = *data;
					return true;
				}
				case THERMAL_DATATYPE_LONG:{
					long *memory = (long *)this->value;
					long *data = (long *)val;
					*memory = *data;
					return true;
				}
				case THERMAL_DATATYPE_LONGINT:{
					long int *memory = (long int *)this->value;
					long int *data = (long int *)val;
					*memory = *data;
					return true;
				}
				case THERMAL_DATATYPE_SIZE:{
					size_t *memory = (size_t *)this->value;
					size_t *data = (size_t *)val;
					*memory = *data;
					return true;
				}
				case THERMAL_DATATYPE_FLOAT:{
					float *memory = (float *)this->value;
					float *data = (float *)val;
					*memory = *data;
					return true;
				}
				case THERMAL_DATATYPE_DOUBLE:{
					double *memory = (double *)this->value;
					double *data = (double *)val;
					*memory = *data;
					return true;
				}
				default:{
					uint64_t *memory = (uint64_t *)this->value;
					uint64_t *data = (uint64_t *)val;
					*memory = *data;
					return true;
				}
			}
			return true;
		}
		int getValueInt(void){
			if(this->value == NULL)
				return 0;
			int ret = static_cast<int *>(this->value)[0];
			return ret;
		}
		bool setValueInt(int val){
			// set the contents of the address this->value to val
			if(this->value == NULL){
				return false;
			}
			int *memory = (int *)this->value;
			*memory = val;
			return true;
		}
		char getValueChar(void){
			if(this->value == NULL)
				return 0x00;
			char ret = static_cast<char *>(this->value)[0];
			return ret;
		}
		float getValueFloat(void){
			if(this->value == NULL)
				return 0.0;
			float *ret = static_cast<float*>(this->value);
			return ret[0];
		}
		double getValueDouble(void){
			if(this->value == NULL)
				return 0.0;
			double ret = static_cast<double *>(this->value)[0];
			return ret;
		}
		size_t getValueSize_t(void){
			if(this->value == NULL)
				return 0;
			size_t ret = ((size_t *)this->value)[0];
			return ret;
		}
		long getValueLong(void){
			if(this->value == NULL)
				return 0;
			long ret = ((long *)this->value)[0];
			return ret;
		}
		uint32_t getValueUint32(void){
			if(this->value == NULL)
				return 0;
			uint32_t ret = static_cast<uint32_t *>(this->value)[0];
			return ret;
		}
		uint64_t getValueUint64(void){
			if(this->value == NULL)
				return 0;
			uint64_t ret = static_cast<uint64_t *>(this->value)[0];
			return ret;
		}
};
