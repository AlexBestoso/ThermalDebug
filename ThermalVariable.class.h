// NOTE: We may want to use static_cast<type>(this->value) to handle returning values.
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
		void create(std::string t, std::string n, size_t *v){
			this->create(t, n, (void *)v);
		}
		void create(std::string t, std::string n, long *v){
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
		void *getValue(void){
			return this->value;
		}
		int getValueInt(void){
			int ret = ((int *)this->value)[0];
			return ret;
		}
		char getValueChar(void){
			char ret = ((char *)this->value)[0];
			return ret;
		}
		float getValueFloat(void){
			float ret = ((float *)this->value)[0];
			return ret;
		}
		double getValueDouble(void){
			double ret = ((double *)this->value)[0];
			return ret;
		}
		size_t getValueSize_t(void){
			size_t ret = ((size_t *)this->value)[0];
			return ret;
		}
		long getValueLong(void){
			long ret = ((long *)this->value)[0];
			return ret;
		}
		
		
	
};
