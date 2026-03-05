class ThermalBackgroundBox : public ThermalBox{
	private:
		thermbox_t *_data;
	public:

		ThermalBackgroundBox(){
			ThermalBox();
			this->_data = this->getData();
			// TODO: Add xml config file loading here.
			this->_data->corner_top_left = THERMAL_BOXLINE_CORNER_TL_LIGHT;
			this->_data->corner_top_right = THERMAL_BOXLINE_CORNER_TR_LIGHT;
			this->_data->corner_bottom_left = THERMAL_BOXLINE_CORNER_BL_LIGHT;
			this->_data->corner_bottom_right = THERMAL_BOXLINE_CORNER_BR_LIGHT;
			this->_data->edge_top = THERMAL_BOXLINE_HOR_LIGHT;
			this->_data->edge_bottom = THERMAL_BOXLINE_HOR_LIGHT;
			this->_data->edge_left = THERMAL_BOXLINE_VER_LIGHT;
			this->_data->edge_right = THERMAL_BOXLINE_VER_LIGHT;
			this->_data->fill = THERMAL_BOXELEMENT_EMPTY;

			this->_data->width = 0;
			this->_data->height = 0;
			this->_data->data_size = 0;
			this->_data->data = NULL;
		}
		
		bool generateData(void){
			if(this->_data == NULL){
				printf("thermbox_t *box is null\n");
				return false;
			}
			if(this->_data == NULL || this->_data->data_size <= 0){
				printf("thermbox_t *box->data isn't allocated\n");
				return false;
			}

			if(!this->generateBoxData()){
				printf("ThermalBox::generateBoxData() failed to generate background data.\n");
				return false;
			}
			
			return true; 
		}

};
