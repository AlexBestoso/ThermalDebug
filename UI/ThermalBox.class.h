#define THERMAL_MASK_BORDERTYPE 0x000ff000
#define THERMAL_BOXLINE 0x000010000

#define THERMAL_BOXLINE_HOR THERMAL_BOXLINE + 0x00001000
#define THERMAL_BOXLINE_HOR_LIGHT THERMAL_BOXLINE_HOR + 0
#define THERMAL_BOXLINE_HOR_DARK THERMAL_BOXLINE_HOR + 1
#define THERMAL_BOXLINE_HOR_LIGHT3DOT THERMAL_BOXLINE_HOR + 2
#define THERMAL_BOXLINE_HOR_DARK3DOT THERMAL_BOXLINE_HOR + 3
#define THERMAL_BOXLINE_HOR_LIGHT4DOT THERMAL_BOXLINE_HOR + 4
#define THERMAL_BOXLINE_HOR_DARK4DOT THERMAL_BOXLINE_HOR + 5
#define THERMAL_BOXLINE_HOR_DOUBLELINE THERMAL_BOXLINE_HOR + 6
#define THERMAL_BOXLINE_HOR_LIGHT2DOT THERMAL_BOXLINE_HOR + 7
#define THERMAL_BOXLINE_HOR_DARK2DOT THERMAL_BOXLINE_HOR + 8
#define THERMAL_BOXLINE_HOR_LIGHTLEFT THERMAL_BOXLINE_HOR + 9
#define THERMAL_BOXLINE_HOR_LIGHTRIGHT THERMAL_BOXLINE_HOR + 10
#define THERMAL_BOXLINE_HOR_DARKLEFT THERMAL_BOXLINE_HOR + 11
#define THERMAL_BOXLINE_HOR_DARKRIGHT THERMAL_BOXLINE_HOR + 12
#define THERMAL_BOXLINE_HOR_TEARRIGHT THERMAL_BOXLINE_HOR + 13
#define THERMAL_BOXLINE_HOR_TEARLEFT THERMAL_BOXLINE_HOR + 14

#define THERMAL_BOXLINE_VER THERMAL_BOXLINE + 0x00002000
#define THERMAL_BOXLINE_VER_LIGHT THERMAL_BOXLINE_VER + 0
#define THERMAL_BOXLINE_VER_DARK THERMAL_BOXLINE_VER + 1
#define THERMAL_BOXLINE_VER_LIGHT3DOT THERMAL_BOXLINE_VER + 2
#define THERMAL_BOXLINE_VER_DARK3DOT THERMAL_BOXLINE_VER + 3
#define THERMAL_BOXLINE_VER_LIGHT4DOT THERMAL_BOXLINE_VER + 4
#define THERMAL_BOXLINE_VER_DARK4DOT THERMAL_BOXLINE_VER + 5
#define THERMAL_BOXLINE_VER_LIGHT2DOT THERMAL_BOXLINE_VER + 6
#define THERMAL_BOXLINE_VER_DARK2DOT THERMAL_BOXLINE_VER + 7
#define THERMAL_BOXLINE_VER_DOUBLELINE THERMAL_BOXLINE_VER + 8
#define THERMAL_BOXLINE_VER_LIGHTTOP THERMAL_BOXLINE_VER + 9
#define THERMAL_BOXLINE_VER_LIGHTBOTTOM THERMAL_BOXLINE_VER + 10
#define THERMAL_BOXLINE_VER_DARKTOP THERMAL_BOXLINE_VER + 11
#define THERMAL_BOXLINE_VER_DARK_BOTTOM THERMAL_BOXLINE_VER + 12
#define THERMAL_BOXLINE_VER_TEARDOWN THERMAL_BOXLINE_VER + 13
#define THERMAL_BOXLINE_VER_TEARUP THERMAL_BOXLINE_VER + 14

#define THERMAL_BOXLINE_CORNER THERMAL_BOXLINE + 0x00003000
#define THERMAL_BOXLINE_CORNER_TL_LIGHT THERMAL_BOXLINE_CORNER + 0
#define THERMAL_BOXLINE_CORNER_TL_LVERDHOR THERMAL_BOXLINE_CORNER + 1
#define THERMAL_BOXLINE_CORNER_TL_DVERLHOR THERMAL_BOXLINE_CORNER + 2
#define THERMAL_BOXLINE_CORNER_TL_DARK THERMAL_BOXLINE_CORNER + 3
#define THERMAL_BOXLINE_CORNER_TR_LIGHT THERMAL_BOXLINE_CORNER + 4
#define THERMAL_BOXLINE_CORNER_TR_LVERDHOR THERMAL_BOXLINE_CORNER + 5
#define THERMAL_BOXLINE_CORNER_TR_DVERLHOR THERMAL_BOXLINE_CORNER + 6
#define THERMAL_BOXLINE_CORNER_TR_DARK THERMAL_BOXLINE_CORNER + 7
#define THERMAL_BOXLINE_CORNER_BL_LIGHT THERMAL_BOXLINE_CORNER + 8
#define THERMAL_BOXLINE_CORNER_BL_LVERDHOR THERMAL_BOXLINE_CORNER + 9
#define THERMAL_BOXLINE_CORNER_BL_DVERLHOR THERMAL_BOXLINE_CORNER + 10
#define THERMAL_BOXLINE_CORNER_BL_DARK THERMAL_BOXLINE_CORNER + 11
#define THERMAL_BOXLINE_CORNER_BR_LIGHT THERMAL_BOXLINE_CORNER + 12
#define THERMAL_BOXLINE_CORNER_BR_LVERDHOR THERMAL_BOXLINE_CORNER + 13
#define THERMAL_BOXLINE_CORNER_BR_DVERLHOR THERMAL_BOXLINE_CORNER + 14
#define THERMAL_BOXLINE_CORNER_BR_DARK THERMAL_BOXLINE_CORNER + 15
#define THERMAL_BOXLINE_CORNER_TL_1VER2HOR THERMAL_BOXLINE_CORNER + 16
#define THERMAL_BOXLINE_CORNER_TL_2VER1HOR THERMAL_BOXLINE_CORNER + 17
#define THERMAL_BOXLINE_CORNER_TL_DOUBLE THERMAL_BOXLINE_CORNER + 18
#define THERMAL_BOXLINE_CORNER_TR_1VER_2HOR THERMAL_BOXLINE_CORNER + 19
#define THERMAL_BOXLINE_CORNER_TR_2VER1HOR THERMAL_BOXLINE_CORNER + 20
#define THERMAL_BOXLINE_CORNER_TR_DOUBLE THERMAL_BOXLINE_CORNER + 21
#define THERMAL_BOXLINE_CORNER_BL_1VER2HOR THERMAL_BOXLINE_CORNER + 22
#define THERMAL_BOXLINE_CORNER_BL_2VER1HOR THERMAL_BOXLINE_CORNER + 23
#define THERMAL_BOXLINE_CORNER_BL_DOUBLE THERMAL_BOXLINE_CORNER + 24
#define THERMAL_BOXLINE_CORNER_BR_1VER2HOR THERMAL_BOXLINE_CORNER + 25
#define THERMAL_BOXLINE_CORNER_BR_2VER1HOR THERMAL_BOXLINE_CORNER + 26
#define THERMAL_BOXLINE_CORNER_BR_DOUBLE THERMAL_BOXLINE_CORNER + 27
#define THERMAL_BOXLINE_CORNER_TL_ROUND THERMAL_BOXLINE_CORNER + 28
#define THERMAL_BOXLINE_CORNER_TR_ROUND THERMAL_BOXLINE_CORNER + 29
#define THERMAL_BOXLINE_CORNER_BR_ROUND THERMAL_BOXLINE_CORNER + 30
#define THERMAL_BOXLINE_CORNER_BL_ROUND THERMAL_BOXLINE_CORNER + 31

#define THERMAL_BOXLINE_T THERMAL_BOXLINE + 0x00004000
#define THERMAL_BOXLINE_T_LEFT_LIGHT THERMAL_BOXLINE_T + 0
#define THERMAL_BOXLINE_T_LEFT_LIGHT_RD THERMAL_BOXLINE_T + 1
#define THERMAL_BOXLINE_T_LEFT_LIGHT_TD THERMAL_BOXLINE_T + 2
#define THERMAL_BOXLINE_T_LEFT_LGHT_BD THERMAL_BOXLINE_T + 3
#define THERMAL_BOXLINE_T_LEFT_DARK_RL THERMAL_BOXLINE_T + 4
#define THERMAL_BOXLINE_T_LEFT_DARK_BL THERMAL_BOXLINE_T + 5
#define THERMAL_BOXLINE_T_LEFT_DARK_TL THERMAL_BOXLINE_T + 6
#define THERMAL_BOXLINE_T_LEFT_DARK THERMAL_BOXLINE_T + 7
#define THERMAL_BOXLINE_T_RIGHT_LIGHT THERMAL_BOXLINE_T + 8 
#define THERMAL_BOXLINE_T_RIGHT_LIGHT_LD THERMAL_BOXLINE_T + 9
#define THERMAL_BOXLINE_T_RIGHT_LIGHT_TD THERMAL_BOXLINE_T + 10
#define THERMAL_BOXLINE_T_RIGHT_LIGHT_BD THERMAL_BOXLINE_T + 11
#define THERMAL_BOXLINE_T_RIGHT_DARK_LL THERMAL_BOXLINE_T + 12
#define THERMAL_BOXLINE_T_RIGHT_DARK_BL THERMAL_BOXLINE_T + 13
#define THERMAL_BOXLINE_T_RIGHT_DARK_TL THERMAL_BOXLINE_T + 14
#define THERMAL_BOXLINE_T_RIGHT_DARK THERMAL_BOXLINE_T + 15
#define THERMAL_BOXLINE_T_TOP_LIGHT THERMAL_BOXLINE_T + 16
#define THERMAL_BOXLINE_T_TOP_LIGHT_LD THERMAL_BOXLINE_T + 17 
#define THERMAL_BOXLINE_T_TOP_LIGHT_RD THERMAL_BOXLINE_T + 18
#define THERMAL_BOXLINE_T_TOP_TD_BL THERMAL_BOXLINE_T + 19
#define THERMAL_BOXLINE_T_TOP_TL_BD THERMAL_BOXLINE_T + 20
#define THERMAL_BOXLINE_T_TOP_DARK_RL THERMAL_BOXLINE_T + 21
#define THERMAL_BOXLINE_T_TOP_DARK_LL THERMAL_BOXLINE_T + 22
#define THERMAL_BOXLINE_T_TOP_DARK THERMAL_BOXLINE_T + 23
#define THERMAL_BOXLINE_T_BOTTOM_LIGHT THERMAL_BOXLINE_T + 24
#define THERMAL_BOXLINE_T_BOTTOM_LIGHT_LD THERMAL_BOXLINE_T + 25
#define THERMAL_BOXLINE_T_BOTTOM_LUIGHT_RD THERMAL_BOXLINE_T + 26
#define THERMAL_BOXLINE_T_BOTTOM_TL_BD THERMAL_BOXLINE_T + 27
#define THERMAL_BOXLINE_T_BOTTOM_TD_BL THERMAL_BOXLINE_T + 28
#define THERMAL_BOXLINE_T_BOTTOM_DARK_RL THERMAL_BOXLINE_T + 29
#define THERMAL_BOXLINE_T_BOTTOM_DARK_LL THERMAL_BOXLINE_T + 30
#define THERMAL_BOXLINE_T_BOTTOM_DARK THERMAL_BOXLINE_T + 31
#define THERMAL_BOXLINE_T_LEFT_LL_RDUB THERMAL_BOXLINE_T + 32
#define THERMAL_BOXLINE_T_LEFT_LDUB_RL THERMAL_BOXLINE_T + 33
#define THERMAL_BOXLINE_T_LEFT_DOUBLE THERMAL_BOXLINE_T + 34
#define THERMAL_BOXLINE_T_RIGHT_LDUB_RL THERMAL_BOXLINE_T + 35
#define THERMAL_BOXLINE_T_RIGHT_LL_RDUB THERMAL_BOXLINE_T + 36
#define THERMAL_BOXLINE_T_RIGHT_DOUBLE THERMAL_BOXLINE_T + 37
#define THERMAL_BOXLINE_T_TOP_TDUB_BL THERMAL_BOXLINE_T + 38
#define THERMAL_BOXLINE_T_TOP_TL_BDUB THERMAL_BOXLINE_T + 39
#define THERMAL_BOXLINE_T_TOP_DOUBLE THERMAL_BOXLINE_T + 40
#define THERMAL_BOXLINE_T_BOTTOM_TL_BDUB THERMAL_BOXLINE_T + 41
#define THERMAL_BOXLINE_T_BOTTOM_TDUB_BL THERMAL_BOXLINE_T + 42
#define THERMAL_BOXLINE_T_BOTTOM_DOUBLE THERMAL_BOXLINE_T + 43

#define THERMAL_BOXLINE_CROSS THERMAL_BOXLINE + 0x00005000
#define THERMAL_BOXLINE_CROSS_LIGHT THERMAL_BOXLINE_CROSS + 0
#define THERMAL_BOXLINE_CROSS_LIGHT_LD THERMAL_BOXLINE_CROSS + 1
#define THERMAL_BOXLINE_CROSS_LIGHT_RD THERMAL_BOXLINE_CROSS + 2
#define THERMAL_BOXLINE_CROSS_LIGHT_HD THERMAL_BOXLINE_CROSS + 3
#define THERMAL_BOXLINE_CROSS_LIGHT_TD THERMAL_BOXLINE_CROSS + 4
#define THERMAL_BOXLINE_CROSS_LIGHT_BD THERMAL_BOXLINE_CROSS + 5
#define THERMAL_BOXLINE_CROSS_LIGHT_VD THERMAL_BOXLINE_CROSS + 6
#define THERMAL_BOXLINE_CROSS_LIGHTBR_DARKTL THERMAL_BOXLINE_CROSS + 7
#define THERMAL_BOXLINE_CROSS_LIGHTBL_DARKTR THERMAL_BOXLINE_CROSS + 8
#define THERMAL_BOXLINE_CROSS_LIGHTTL_DARKBR THERMAL_BOXLINE_CROSS + 9
#define THERMAL_BOXLINE_CROSS_LIGHTTR_DARK_BL THERMAL_BOXLINE_CROSS + 10
#define THERMAL_BOXLINE_CROSS_DARK_BL THERMAL_BOXLINE_CROSS + 11
#define THERMAL_BOXLINE_CROSS_DARK_TL THERMAL_BOXLINE_CROSS + 12
#define THERMAL_BOXLINE_CROSS_DARK_RL THERMAL_BOXLINE_CROSS + 13
#define THERMAL_BOXLINE_CROSS_DARK_LL THERMAL_BOXLINE_CROSS + 14
#define THERMAL_BOXLINE_CROSS_DARK THERMAL_BOXLINE_CROSS + 15
#define THERMAL_BOXLINE_CROSS_LIGHT_DUBHOR THERMAL_BOXLINE_CROSS + 16
#define THERMAL_BOXLINE_CROSS_LIGHT_DUBVER THERMAL_BOXLINE_CROSS + 17
#define THERMAL_BOXLINE_CROSS_DOUBLE THERMAL_BOXLINE_CROSS + 18

#define THERMAL_BOXLINE_MISC THERMAL_BOXLINE + 0x00006000
#define THERMAL_BOXLINE_MISC_FORWARDSLASH THERMAL_BOXLINE_MISC + 0
#define THERMAL_BOXLINE_MISC_BACKSLASH THERMAL_BOXLINE_MISC + 1
#define THERMAL_BOXLINE_MISC_X THERMAL_BOXLINE_MISC + 2

#define THERMAL_BOXFILL 0x00020000
#define THERMAL_BOXFILL_UPPER_HALF THERMAL_BOXFILL + 0
#define THERMAL_BOXFILL_LOWER_EIGHTH THERMAL_BOXFILL + 1
#define THERMAL_BOXFILL_LOWER_QUARTER THERMAL_BOXFILL + 2
#define THERMAL_BOXFILL_LOWER_3EIGHTH THERMAL_BOXFILL + 3
#define THERMAL_BOXFILL_LOWER_HALF THERMAL_BOXFILL + 4
#define THERMAL_BOXFILL_LOWER_5EIGHTH THERMAL_BOXFILL + 5
#define THERMAL_BOXFILL_LOWER_3QUARTER THERMAL_BOXFILL + 6
#define THERMAL_BOXFILL_LOWER_7EIGHTH THERMAL_BOXFILL + 7
#define THERMAL_BOXFILL_FULL THERMAL_BOXFILL + 8
#define THERMAL_BOXFILL_LEFT_7EIGHTH THERMAL_BOXFILL + 9
#define THERMAL_BOXFILL_LEFT_3QUARTER THERMAL_BOXFILL + 10
#define THERMAL_BOXFILL_LEFT_5EIGHTH THERMAL_BOXFILL + 11
#define THERMAL_BOXFILL_LEFT_HALF THERMAL_BOXFILL + 12
#define THERMAL_BOXFILL_LEFT_3EIGHTH THERMAL_BOXFILL + 13
#define THERMAL_BOXFILL_LEFT_EIGHTH THERMAL_BOXFILL + 14
#define THERMAL_BOXFILL_RIGHT_HALF THERMAL_BOXFILL + 15
#define THERMAL_BOXFILL_SHADE_LIGHT THERMAL_BOXFILL + 16
#define THERMAL_BOXFILL_SHADE_MEDIUM THERMAL_BOXFILL + 17
#define THERMAL_BOXFILL_SHADE_DARK THERMAL_BOXFILL + 18
#define THERMAL_BOXFILL_UPPER_EIGHTH THERMAL_BOXFILL + 19
#define THERMAL_BOXFILL_RIGHT_EIGHTH THERMAL_BOXFILL + 20
#define THERMAL_BOXFILL_QUAD_LEFT_LOWER THERMAL_BOXFILL + 21
#define THERMAL_BOXFILL_QUAD_RIGHT_LOWER THERMAL_BOXFILL + 22
#define THERMAL_BOXFILL_QUAD_LEFT_UPPER THERMAL_BOXFILL + 23
#define THERMAL_BOXFILL_QUAD_NO_RIGHT_TOP THERMAL_BOXFILL + 24
#define THERMAL_BOXFILL_QUAD_LEFT_DIAG THERMAL_BOXFILL + 25
#define THERMAL_BOXFILL_QUAD_NO_RIGHT_BOTTOM THERMAL_BOXFILL + 26
#define THERMAL_BOXFILL_QUAD_NO_LEFT_BOTTOM THERMAL_BOXFILL + 27
#define THERMAL_BOXFILL_QUAD_RIGHT_UPPER THERMAL_BOXFILL + 28
#define THERMAL_BOXFILL_QUAD_RIGHT_DIAG THERMAL_BOXFILL + 29
#define THERMAL_BOXFILL_QUAD_NO_LEFT_TOP THERMAL_BOXFILL + 30
#define THERMAL_BOXFILL_EMPTY THERMAL_BOXFILL + 31
// depreicated
#define THERMAL_BOXELEMENT_EMPTY THERMAL_BOXFILL_EMPTY

#define THERMAL_BOXEDGE 0x00030000
#define THERMAL_BOXEDGE_TOP THERMAL_BOXEDGE + 0
#define THERMAL_BOXEDGE_BOTTOM THERMAL_BOXEDGE + 1
#define THERMAL_BOXEDGE_LEFT THERMAL_BOXEDGE + 2
#define THERMAL_BOXEDGE_RIGHT THERMAL_BOXEDGE + 3

#define THERMAL_INTERSECT_ERR 0x10000
#define THERMAL_INTERSECT_ERR_LEFT 0x01000
#define THERMAL_INTERSECT_ERR_RIGHT 0x00100
#define THERMAL_INTERSECT_ERR_UP 0x00010
#define THERMAL_INTERSECT_ERR_DOWN 0x00001

struct thermalBoxStruct{	
	int pos_offset_x;
	int pos_offset_y;

	int pos_corner_top_left;
	int pos_corner_top_right;
	int pos_corner_bottom_left;
	int pos_corner_bottom_right;

	int corner_top_left;
	int corner_top_right;
	int corner_bottom_left;
	int corner_bottom_right;
	int edge_top;
	int edge_bottom;
	int edge_left;
	int edge_right;
	int fill;
	int width;
	int height;
	size_t data_size;
	wchar_t *data;
};
typedef struct thermalBoxStruct thermbox_t;

class ThermalBox{
	private:
		thermbox_t data;

		bool validateCornerPositions(void){
			int max = this->data.data_size;
			if(max <= 0) return false;
			if(this->data.pos_corner_top_left < 0 || this->data.pos_corner_top_left >= max)
				return false;
			if(this->data.pos_corner_top_right < 0 || this->data.pos_corner_top_right >= max)
				return false;
			if(this->data.pos_corner_bottom_left < 0 || this->data.pos_corner_bottom_left >= max)
				return false;
			if(this->data.pos_corner_bottom_right < 0 || this->data.pos_corner_bottom_right >= max)
				return false;
			return true;
		}

		bool positionIsCorner(int iTest){
			if(iTest == this->data.pos_corner_top_left || 
			   iTest == this->data.pos_corner_top_right ||
			   iTest == this->data.pos_corner_bottom_left ||
			   iTest == this->data.pos_corner_bottom_right){
				return true;
			}
			return false;
		}

		bool positionIsHorizontal(int iTest){
			if(this->positionIsCorner(iTest)) return false;

			if(this->data.data == NULL || this->data.data_size <= 0)
				return false;
			
			int endStart = this->data.data_size-this->data.width;
			int endEnd = this->data.data_size - 1;

			if(iTest > 0 && iTest < this->data.width || 
			   iTest > endStart && iTest < endEnd){
				return true;
			}
			return false;
		}

		bool positionIsVertical(int iTest){
			if(this->positionIsCorner(iTest)) return false;
			if(this->data.data == NULL || this->data.data_size <= 0)
				return false;
			for(int i=0; i<this->data.data_size; i+= this->data.width){
				if(iTest == i) return true;
				else if(iTest == (i+(this->data.width - 1)))
					return true;
			}

			return false;
		}

	public:
		ThermalBox(){

		}

		~ThermalBox(){

		}

		thermbox_t *getData(){
			return &this->data;
		}
		wchar_t horizontalLine(int style){
			switch(style){
				case THERMAL_BOXELEMENT_EMPTY:
					return L' ';
				case THERMAL_BOXLINE_HOR_DARK:
					return L'━';
				case THERMAL_BOXLINE_HOR_LIGHT3DOT:
					return L'┄';
				case THERMAL_BOXLINE_HOR_DARK3DOT:
					return L'┅';
				case THERMAL_BOXLINE_HOR_LIGHT4DOT:
					return L'┈';
				case THERMAL_BOXLINE_HOR_DARK4DOT:
					return L'┉';
				case THERMAL_BOXLINE_HOR_DOUBLELINE:
					return L'═';
				case THERMAL_BOXLINE_HOR_LIGHT2DOT:
					return L'╌';
				case THERMAL_BOXLINE_HOR_DARK2DOT:
					return L'╍';
				case THERMAL_BOXLINE_HOR_LIGHTLEFT:
					return L'╴';
				case THERMAL_BOXLINE_HOR_LIGHTRIGHT:
					return L'╶';
				case THERMAL_BOXLINE_HOR_DARKLEFT:
					return L'╸';
				case THERMAL_BOXLINE_HOR_DARKRIGHT:
					return L'╺';
				case THERMAL_BOXLINE_HOR_TEARRIGHT:
					return L'╼';
				case THERMAL_BOXLINE_HOR_TEARLEFT:
					return L'╾';
				default: // THERMAL_BOXLINE_HOR_LIGHT
					return L'─';
			}
		}

		wchar_t verticalLine(int style){
			switch(style){
				case THERMAL_BOXELEMENT_EMPTY:
					return L' ';
				case THERMAL_BOXLINE_VER_DARK:
					return L'┃';
				case THERMAL_BOXLINE_VER_LIGHT3DOT:
					return L'┆';
				case THERMAL_BOXLINE_VER_DARK3DOT:
					return L'┇';
				case THERMAL_BOXLINE_VER_LIGHT4DOT:
					return L'┊';
				case THERMAL_BOXLINE_VER_DARK4DOT:
					return L'┋';
				case THERMAL_BOXLINE_VER_LIGHT2DOT:
					return L'╎';
				case THERMAL_BOXLINE_VER_DARK2DOT:
					return L'╏';
				case THERMAL_BOXLINE_VER_DOUBLELINE:
					return L'║';
				case THERMAL_BOXLINE_VER_LIGHTTOP:
					return L'╵';
				case THERMAL_BOXLINE_VER_LIGHTBOTTOM:
					return L'╷';
				case THERMAL_BOXLINE_VER_DARKTOP:
					return L'╹';
				case THERMAL_BOXLINE_VER_DARK_BOTTOM:
					return L'╻';
				case THERMAL_BOXLINE_VER_TEARDOWN:
					return L'╽';
				case THERMAL_BOXLINE_VER_TEARUP:
					return L'╿';
				default: // THERMAL_BOXLINE_VER_LIGHT
					return L'│';
			}
		}

		wchar_t cornerLine(int style){
			switch(style){
				case THERMAL_BOXELEMENT_EMPTY:
					return L' ';
				case THERMAL_BOXLINE_CORNER_TL_LVERDHOR:
					return L'┍';
				case THERMAL_BOXLINE_CORNER_TL_DVERLHOR:
					return L'┎';
				case THERMAL_BOXLINE_CORNER_TL_DARK:
					return L'┏';
				case THERMAL_BOXLINE_CORNER_TR_LIGHT:
					return L'┐';
				case THERMAL_BOXLINE_CORNER_TR_LVERDHOR:
					return L'┑';
				case THERMAL_BOXLINE_CORNER_TR_DVERLHOR:
					return L'┒';
				case THERMAL_BOXLINE_CORNER_TR_DARK:
					return L'┓';
				case THERMAL_BOXLINE_CORNER_BL_LIGHT:
					return L'└';
				case THERMAL_BOXLINE_CORNER_BL_LVERDHOR:
					return L'┕';
				case THERMAL_BOXLINE_CORNER_BL_DVERLHOR:
					return L'┖';
				case THERMAL_BOXLINE_CORNER_BL_DARK:
					return L'┗';
				case THERMAL_BOXLINE_CORNER_BR_LIGHT:
					return L'┘';
				case THERMAL_BOXLINE_CORNER_BR_LVERDHOR:
					return L'┙';
				case THERMAL_BOXLINE_CORNER_BR_DVERLHOR:
					return L'┚';
				case THERMAL_BOXLINE_CORNER_BR_DARK:
					return L'┛';
				case THERMAL_BOXLINE_CORNER_TL_1VER2HOR:
					return L'╒';
				case THERMAL_BOXLINE_CORNER_TL_2VER1HOR:
					return L'╓';
				case THERMAL_BOXLINE_CORNER_TL_DOUBLE:
					return L'╔';
				case THERMAL_BOXLINE_CORNER_TR_1VER_2HOR:
					return L'╕';
				case THERMAL_BOXLINE_CORNER_TR_2VER1HOR:
					return L'╖';
				case THERMAL_BOXLINE_CORNER_TR_DOUBLE:
					return L'╗';
				case THERMAL_BOXLINE_CORNER_BL_1VER2HOR:
					return L'╘';
				case THERMAL_BOXLINE_CORNER_BL_2VER1HOR:
					return L'╙';
				case THERMAL_BOXLINE_CORNER_BL_DOUBLE:
					return L'╚';
				case THERMAL_BOXLINE_CORNER_BR_1VER2HOR:
					return L'╛';
				case THERMAL_BOXLINE_CORNER_BR_2VER1HOR:
					return L'╜';
				case THERMAL_BOXLINE_CORNER_BR_DOUBLE:
					return L'╝';
				case THERMAL_BOXLINE_CORNER_TL_ROUND:
					return L'╭';
				case THERMAL_BOXLINE_CORNER_TR_ROUND:
					return L'╮';
				case THERMAL_BOXLINE_CORNER_BR_ROUND:
					return L'╯';
				case THERMAL_BOXLINE_CORNER_BL_ROUND:
					return L'╰';
				default: // THERMAL_BOXLINE_CORNER_TL_LIGHT
					return L'┌';
			}
		}
		
		wchar_t tLine(int style){
			switch(style){
				case THERMAL_BOXELEMENT_EMPTY:
					return L' ';
				case THERMAL_BOXLINE_T_LEFT_LIGHT_RD:
					return L'┝';
				case THERMAL_BOXLINE_T_LEFT_LIGHT_TD:
					return L'┞';
				case THERMAL_BOXLINE_T_LEFT_LGHT_BD:
					return L'┟';
				case THERMAL_BOXLINE_T_LEFT_DARK_RL:
					return L'┠';
				case THERMAL_BOXLINE_T_LEFT_DARK_BL:
					return L'┡';
				case THERMAL_BOXLINE_T_LEFT_DARK_TL:
					return L'┢';
				case THERMAL_BOXLINE_T_LEFT_DARK:
					return L'┣';
				case THERMAL_BOXLINE_T_RIGHT_LIGHT:
					return L'┤';
				case THERMAL_BOXLINE_T_RIGHT_LIGHT_LD:
					return L'┥';
				case THERMAL_BOXLINE_T_RIGHT_LIGHT_TD:
					return L'┦';
				case THERMAL_BOXLINE_T_RIGHT_LIGHT_BD:
					return L'┧';
				case THERMAL_BOXLINE_T_RIGHT_DARK_LL:
					return L'┨';
				case THERMAL_BOXLINE_T_RIGHT_DARK_BL:
					return L'┩';
				case THERMAL_BOXLINE_T_RIGHT_DARK_TL:
					return L'┪';
				case THERMAL_BOXLINE_T_RIGHT_DARK:
					return L'┫';
				case THERMAL_BOXLINE_T_TOP_LIGHT:
					return L'┬';
				case THERMAL_BOXLINE_T_TOP_LIGHT_LD:
					return L'┭';
				case THERMAL_BOXLINE_T_TOP_LIGHT_RD:
					return L'┮';
				case THERMAL_BOXLINE_T_TOP_TD_BL:
					return L'┯';
				case THERMAL_BOXLINE_T_TOP_TL_BD:
					return L'┰';
				case THERMAL_BOXLINE_T_TOP_DARK_RL:
					return L'┱';
				case THERMAL_BOXLINE_T_TOP_DARK_LL:
					return L'┲';
				case THERMAL_BOXLINE_T_TOP_DARK:
					return L'┳';
				case THERMAL_BOXLINE_T_BOTTOM_LIGHT:
					return L'┴';
				case THERMAL_BOXLINE_T_BOTTOM_LIGHT_LD:
					return L'┵';
				case THERMAL_BOXLINE_T_BOTTOM_LUIGHT_RD:
					return L'┶';
				case THERMAL_BOXLINE_T_BOTTOM_TL_BD:
					return L'┷';
				case THERMAL_BOXLINE_T_BOTTOM_TD_BL:
					return L'┸';
				case THERMAL_BOXLINE_T_BOTTOM_DARK_RL:
					return L'┹';
				case THERMAL_BOXLINE_T_BOTTOM_DARK_LL:
					return L'┺';
				case THERMAL_BOXLINE_T_BOTTOM_DARK:
					return L'┻';
				case THERMAL_BOXLINE_T_LEFT_LL_RDUB:
					return L'╞';
				case THERMAL_BOXLINE_T_LEFT_LDUB_RL:
					return L'╟';
				case THERMAL_BOXLINE_T_LEFT_DOUBLE:
					return L'╠';
				case THERMAL_BOXLINE_T_RIGHT_LDUB_RL:
					return L'╡';
				case THERMAL_BOXLINE_T_RIGHT_LL_RDUB:
					return L'╢';
				case THERMAL_BOXLINE_T_RIGHT_DOUBLE:
					return L'╣';
				case THERMAL_BOXLINE_T_TOP_TDUB_BL:
					return L'╤';
				case THERMAL_BOXLINE_T_TOP_TL_BDUB:
					return L'╥';
				case THERMAL_BOXLINE_T_TOP_DOUBLE:
					return L'╦';
				case THERMAL_BOXLINE_T_BOTTOM_TL_BDUB:
					return L'╧';
				case THERMAL_BOXLINE_T_BOTTOM_TDUB_BL:
					return L'╨';
				case THERMAL_BOXLINE_T_BOTTOM_DOUBLE:
					return L'╩';
				default: //THERMAL_BOXLINE_T_LEFT_LIGHT:
					return L'├';
			}
		}

		wchar_t crossLine(int style){
			switch(style){
				case THERMAL_BOXELEMENT_EMPTY:
					return L' ';
				case THERMAL_BOXLINE_CROSS_LIGHT_LD:
					return L'┽';
				case THERMAL_BOXLINE_CROSS_LIGHT_RD:
					return L'┾';
				case THERMAL_BOXLINE_CROSS_LIGHT_HD:
					return L'┿';
				case THERMAL_BOXLINE_CROSS_LIGHT_TD:
					return L'╀';
				case THERMAL_BOXLINE_CROSS_LIGHT_BD:
					return L'╁';
				case THERMAL_BOXLINE_CROSS_LIGHT_VD:
					return L'╂';
				case THERMAL_BOXLINE_CROSS_LIGHTBR_DARKTL:
					return L'╃';
				case THERMAL_BOXLINE_CROSS_LIGHTBL_DARKTR:
					return L'╄';
				case THERMAL_BOXLINE_CROSS_LIGHTTL_DARKBR:
					return L'╅';
				case THERMAL_BOXLINE_CROSS_LIGHTTR_DARK_BL:
					return L'╆';
				case THERMAL_BOXLINE_CROSS_DARK_BL:
					return L'╇';
				case THERMAL_BOXLINE_CROSS_DARK_TL:
					return L'╈';
				case THERMAL_BOXLINE_CROSS_DARK_RL:
					return L'╉';
				case THERMAL_BOXLINE_CROSS_DARK_LL:
					return L'╊';
				case THERMAL_BOXLINE_CROSS_DARK:
					return L'╋';
				case THERMAL_BOXLINE_CROSS_LIGHT_DUBHOR:
					return L'╪';
				case THERMAL_BOXLINE_CROSS_LIGHT_DUBVER:
					return L'╫';
				case THERMAL_BOXLINE_CROSS_DOUBLE:
					return L'╬';
				default: //THERMAL_BOXLINE_CROSS_LIGHT:
					return L'┼';
			}
		}
		
		wchar_t blockFill(int style){
			switch(style){
				case THERMAL_BOXELEMENT_EMPTY:
					return L' ';
				case THERMAL_BOXFILL_LOWER_EIGHTH:
					return L'▁';
				case THERMAL_BOXFILL_LOWER_QUARTER:
					return L'▂';
				case THERMAL_BOXFILL_LOWER_3EIGHTH:
					return L'▃';
				case THERMAL_BOXFILL_LOWER_HALF:
					return L'▄';
				case THERMAL_BOXFILL_LOWER_5EIGHTH:
					return L'▆';
				case THERMAL_BOXFILL_LOWER_3QUARTER:
					return L'▇';
				case THERMAL_BOXFILL_LOWER_7EIGHTH:
					return L'█';
				case THERMAL_BOXFILL_FULL:
					return L'▉';
				case THERMAL_BOXFILL_LEFT_7EIGHTH:
					return L'▊';
				case THERMAL_BOXFILL_LEFT_3QUARTER:
					return L'▋';
				case THERMAL_BOXFILL_LEFT_5EIGHTH:
					return L'▌';
				case THERMAL_BOXFILL_LEFT_HALF:
					return L'▍';
				case THERMAL_BOXFILL_LEFT_3EIGHTH:
					return L'▎';
				case THERMAL_BOXFILL_LEFT_EIGHTH:
					return L'▏';
				case THERMAL_BOXFILL_RIGHT_HALF:
					return L'▐';
				case THERMAL_BOXFILL_SHADE_LIGHT:
					return L'░';
				case THERMAL_BOXFILL_SHADE_MEDIUM:
					return L'▒';
				case THERMAL_BOXFILL_SHADE_DARK:
					return L'▓';
				case THERMAL_BOXFILL_UPPER_EIGHTH:
					return L'▔';
				case THERMAL_BOXFILL_RIGHT_EIGHTH:
					return L'▕';
				case THERMAL_BOXFILL_QUAD_LEFT_LOWER:
					return L'▖';
				case THERMAL_BOXFILL_QUAD_RIGHT_LOWER:
					return L'▗';
				case THERMAL_BOXFILL_QUAD_LEFT_UPPER:
					return L'▘';
				case THERMAL_BOXFILL_QUAD_NO_RIGHT_TOP:
					return L'▙';
				case THERMAL_BOXFILL_QUAD_LEFT_DIAG:
					return L'▚';
				case THERMAL_BOXFILL_QUAD_NO_RIGHT_BOTTOM:
					return L'▛';
				case THERMAL_BOXFILL_QUAD_NO_LEFT_BOTTOM:
					return L'▜';
				case THERMAL_BOXFILL_QUAD_RIGHT_UPPER:
					return L'▝';
				case THERMAL_BOXFILL_QUAD_RIGHT_DIAG:
					return L'▞';
				case THERMAL_BOXFILL_QUAD_NO_LEFT_TOP:
					return L'▟';
				default: //THERMAL_BOXFILL_UPPER_HALF:
					return L'▀';
			}
		}

		wchar_t miscLine(int style){	
			switch(style){
				case THERMAL_BOXELEMENT_EMPTY:
					return L' ';
				case THERMAL_BOXLINE_MISC_BACKSLASH:
					return L'╲';
				case THERMAL_BOXLINE_MISC_X:
					return L'╳';
				default: //THERMAL_BOXLINE_MISC_FORWARDSLASH:
					return L'╱';
			}
		}

		int getBorderMacro(wchar_t target){
			if(target == L' ')
				return THERMAL_BOXELEMENT_EMPTY;
			else if(target == L'━')
				return THERMAL_BOXLINE_HOR_DARK;
			else if(target == L'┄')
				return THERMAL_BOXLINE_HOR_LIGHT3DOT;
			else if(target == L'┅')
				return THERMAL_BOXLINE_HOR_DARK3DOT;
			else if(target == L'┈')
				return THERMAL_BOXLINE_HOR_LIGHT4DOT;
			else if(target == L'┉')
				return THERMAL_BOXLINE_HOR_DARK4DOT;
			else if(target == L'═')
				return THERMAL_BOXLINE_HOR_DOUBLELINE;
			else if(target == L'╌')
				return THERMAL_BOXLINE_HOR_LIGHT2DOT;
			else if(target == L'╍')
				return THERMAL_BOXLINE_HOR_DARK2DOT;
			else if(target == L'╴')
				return THERMAL_BOXLINE_HOR_LIGHTLEFT;
			else if(target == L'╶')
				return THERMAL_BOXLINE_HOR_LIGHTRIGHT;
			else if(target == L'╸')
				return THERMAL_BOXLINE_HOR_DARKLEFT;
			else if(target == L'╺')
				return THERMAL_BOXLINE_HOR_DARKRIGHT;
			else if(target == L'╼')
				return THERMAL_BOXLINE_HOR_TEARRIGHT;
			else if(target == L'╾')
				return THERMAL_BOXLINE_HOR_TEARLEFT;
			else if(target == L'─')
				return THERMAL_BOXLINE_HOR_LIGHT;
			else if(target == L'┃')
				return THERMAL_BOXLINE_VER_DARK;
			else if(target == L'┆')
				return THERMAL_BOXLINE_VER_LIGHT3DOT;
			else if(target == L'┇')
				return THERMAL_BOXLINE_VER_DARK3DOT;
			else if(target == L'┊')
				return THERMAL_BOXLINE_VER_LIGHT4DOT;
			else if(target == L'┋')
				return THERMAL_BOXLINE_VER_DARK4DOT;
			else if(target == L'╎')
				return THERMAL_BOXLINE_VER_LIGHT2DOT;
			else if(target == L'╏')
				return THERMAL_BOXLINE_VER_DARK2DOT;
			else if(target == L'║')
				return THERMAL_BOXLINE_VER_DOUBLELINE;
			else if(target == L'╵')
				return THERMAL_BOXLINE_VER_LIGHTTOP;
			else if(target == L'╷')
				return THERMAL_BOXLINE_VER_LIGHTBOTTOM;
			else if(target == L'╹')
				return THERMAL_BOXLINE_VER_DARKTOP;
			else if(target == L'╻')
				return THERMAL_BOXLINE_VER_DARK_BOTTOM;
			else if(target == L'╽')
				return THERMAL_BOXLINE_VER_TEARDOWN;
			else if(target == L'╿')
				return THERMAL_BOXLINE_VER_TEARUP;
			else if(target == L'│')
				return THERMAL_BOXLINE_VER_LIGHT;
			else if(target == L'┍')
				return THERMAL_BOXLINE_CORNER_TL_LVERDHOR;
			else if(target == L'┎')
				return THERMAL_BOXLINE_CORNER_TL_DVERLHOR;
			else if(target == L'┏')
				return THERMAL_BOXLINE_CORNER_TL_DARK;
			else if(target == L'┐')
				return THERMAL_BOXLINE_CORNER_TR_LIGHT;
			else if(target == L'┑')
				return THERMAL_BOXLINE_CORNER_TR_LVERDHOR;
			else if(target == L'┒')
				return THERMAL_BOXLINE_CORNER_TR_DVERLHOR;
			else if(target == L'┓')
				return THERMAL_BOXLINE_CORNER_TR_DARK;
			else if(target == L'└')
				return THERMAL_BOXLINE_CORNER_BL_LIGHT;
			else if(target == L'┕')
				return THERMAL_BOXLINE_CORNER_BL_LVERDHOR;
			else if(target == L'┖')
				return THERMAL_BOXLINE_CORNER_BL_DVERLHOR;
			else if(target == L'┗')
				return THERMAL_BOXLINE_CORNER_BL_DARK;
			else if(target == L'┘')
				return THERMAL_BOXLINE_CORNER_BR_LIGHT;
			else if(target == L'┙')
				return THERMAL_BOXLINE_CORNER_BR_LVERDHOR;
			else if(target == L'┚')
				return THERMAL_BOXLINE_CORNER_BR_DVERLHOR;
			else if(target == L'┛')
				return THERMAL_BOXLINE_CORNER_BR_DARK;
			else if(target == L'╒')
				return THERMAL_BOXLINE_CORNER_TL_1VER2HOR;
			else if(target == L'╓')
				return THERMAL_BOXLINE_CORNER_TL_2VER1HOR;
			else if(target == L'╔')
				return THERMAL_BOXLINE_CORNER_TL_DOUBLE;
			else if(target == L'╕')
				return THERMAL_BOXLINE_CORNER_TR_1VER_2HOR;
			else if(target == L'╖')
				return THERMAL_BOXLINE_CORNER_TR_2VER1HOR;
			else if(target == L'╗')
				return THERMAL_BOXLINE_CORNER_TR_DOUBLE;
			else if(target == L'╘')
				return THERMAL_BOXLINE_CORNER_BL_1VER2HOR;
			else if(target == L'╙')
				return THERMAL_BOXLINE_CORNER_BL_2VER1HOR;
			else if(target == L'╚')
				return THERMAL_BOXLINE_CORNER_BL_DOUBLE;
			else if(target == L'╛')
				return THERMAL_BOXLINE_CORNER_BR_1VER2HOR;
			else if(target == L'╜')
				return THERMAL_BOXLINE_CORNER_BR_2VER1HOR;
			else if(target == L'╝')
				return THERMAL_BOXLINE_CORNER_BR_DOUBLE;
			else if(target == L'╭')
				return THERMAL_BOXLINE_CORNER_TL_ROUND;
			else if(target == L'╮')
				return THERMAL_BOXLINE_CORNER_TR_ROUND;
			else if(target == L'╯')
				return THERMAL_BOXLINE_CORNER_BR_ROUND;
			else if(target == L'╰')
				return THERMAL_BOXLINE_CORNER_BL_ROUND;
			else if(target == L'┌')
				return THERMAL_BOXLINE_CORNER_TL_LIGHT;
			else if(target == L' ')
				return THERMAL_BOXELEMENT_EMPTY;
			else if(target == L'┝')
				return THERMAL_BOXLINE_T_LEFT_LIGHT_RD;
			else if(target == L'┞')
				return THERMAL_BOXLINE_T_LEFT_LIGHT_TD;
			else if(target == L'┟')
				return THERMAL_BOXLINE_T_LEFT_LGHT_BD;
			else if(target == L'┠')
				return THERMAL_BOXLINE_T_LEFT_DARK_RL;
			else if(target == L'┡')
				return THERMAL_BOXLINE_T_LEFT_DARK_BL;
			else if(target == L'┢')
				return THERMAL_BOXLINE_T_LEFT_DARK_TL;
			else if(target == L'┣')
				return THERMAL_BOXLINE_T_LEFT_DARK;
			else if(target == L'┤')
				return THERMAL_BOXLINE_T_RIGHT_LIGHT;
			else if(target == L'┥')
				return THERMAL_BOXLINE_T_RIGHT_LIGHT_LD;
			else if(target == L'┦')
				return THERMAL_BOXLINE_T_RIGHT_LIGHT_TD;
			else if(target == L'┧')
				return THERMAL_BOXLINE_T_RIGHT_LIGHT_BD;
			else if(target == L'┨')
				return THERMAL_BOXLINE_T_RIGHT_DARK_LL;
			else if(target == L'┩')
				return THERMAL_BOXLINE_T_RIGHT_DARK_BL;
			else if(target == L'┪')
				return THERMAL_BOXLINE_T_RIGHT_DARK_TL;
			else if(target == L'┫')
				return THERMAL_BOXLINE_T_RIGHT_DARK;
			else if(target == L'┬')
				return THERMAL_BOXLINE_T_TOP_LIGHT;
			else if(target == L'┭')
				return THERMAL_BOXLINE_T_TOP_LIGHT_LD;
			else if(target == L'┮')
				return THERMAL_BOXLINE_T_TOP_LIGHT_RD;
			else if(target == L'┯')
				return THERMAL_BOXLINE_T_TOP_TD_BL;
			else if(target == L'┰')
				return THERMAL_BOXLINE_T_TOP_TL_BD;
			else if(target == L'┱')
				return THERMAL_BOXLINE_T_TOP_DARK_RL;
			else if(target == L'┲')
				return THERMAL_BOXLINE_T_TOP_DARK_LL;
			else if(target == L'┳')
				return THERMAL_BOXLINE_T_TOP_DARK;
			else if(target == L'┴')
				return THERMAL_BOXLINE_T_BOTTOM_LIGHT;
			else if(target == L'┵')
				return THERMAL_BOXLINE_T_BOTTOM_LIGHT_LD;
			else if(target == L'┶')
				return THERMAL_BOXLINE_T_BOTTOM_LUIGHT_RD;
			else if(target == L'┷')
				return THERMAL_BOXLINE_T_BOTTOM_TL_BD;
			else if(target == L'┸')
				return THERMAL_BOXLINE_T_BOTTOM_TD_BL;
			else if(target == L'┹')
				return THERMAL_BOXLINE_T_BOTTOM_DARK_RL;
			else if(target == L'┺')
				return THERMAL_BOXLINE_T_BOTTOM_DARK_LL;
			else if(target == L'┻')
				return THERMAL_BOXLINE_T_BOTTOM_DARK;
			else if(target == L'╞')
				return THERMAL_BOXLINE_T_LEFT_LL_RDUB;
			else if(target == L'╟')
				return THERMAL_BOXLINE_T_LEFT_LDUB_RL;
			else if(target == L'╠')
				return THERMAL_BOXLINE_T_LEFT_DOUBLE;
			else if(target == L'╡')
				return THERMAL_BOXLINE_T_RIGHT_LDUB_RL;
			else if(target == L'╢')
				return THERMAL_BOXLINE_T_RIGHT_LL_RDUB;
			else if(target == L'╣')
				return THERMAL_BOXLINE_T_RIGHT_DOUBLE;
			else if(target == L'╤')
				return THERMAL_BOXLINE_T_TOP_TDUB_BL;
			else if(target == L'╥')
				return THERMAL_BOXLINE_T_TOP_TL_BDUB;
			else if(target == L'╦')
				return THERMAL_BOXLINE_T_TOP_DOUBLE;
			else if(target == L'╧')
				return THERMAL_BOXLINE_T_BOTTOM_TL_BDUB;
			else if(target == L'╨')
				return THERMAL_BOXLINE_T_BOTTOM_TDUB_BL;
			else if(target == L'╩')
				return THERMAL_BOXLINE_T_BOTTOM_DOUBLE;
			else if(target == L'├')
				return THERMAL_BOXLINE_T_LEFT_LIGHT;
			else if(target == L'┽')
				return THERMAL_BOXLINE_CROSS_LIGHT_LD;
			else if(target == L'┾')
				return THERMAL_BOXLINE_CROSS_LIGHT_RD;
			else if(target == L'┿')
				return THERMAL_BOXLINE_CROSS_LIGHT_HD;
			else if(target == L'╀')
				return THERMAL_BOXLINE_CROSS_LIGHT_TD;
			else if(target == L'╁')
				return THERMAL_BOXLINE_CROSS_LIGHT_BD;
			else if(target == L'╂')
				return THERMAL_BOXLINE_CROSS_LIGHT_VD;
			else if(target == L'╃')
				return THERMAL_BOXLINE_CROSS_LIGHTBR_DARKTL;
			else if(target == L'╄')
				return THERMAL_BOXLINE_CROSS_LIGHTBL_DARKTR;
			else if(target == L'╅')
				return THERMAL_BOXLINE_CROSS_LIGHTTL_DARKBR;
			else if(target == L'╆')
				return THERMAL_BOXLINE_CROSS_LIGHTTR_DARK_BL;
			else if(target == L'╇')
				return THERMAL_BOXLINE_CROSS_DARK_BL;
			else if(target == L'╈')
				return THERMAL_BOXLINE_CROSS_DARK_TL;
			else if(target == L'╉')
				return THERMAL_BOXLINE_CROSS_DARK_RL;
			else if(target == L'╊')
				return THERMAL_BOXLINE_CROSS_DARK_LL;
			else if(target == L'╋')
				return THERMAL_BOXLINE_CROSS_DARK;
			else if(target == L'╪')
				return THERMAL_BOXLINE_CROSS_LIGHT_DUBHOR;
			else if(target == L'╫')
				return THERMAL_BOXLINE_CROSS_LIGHT_DUBVER;
			else if(target == L'╬')
				return THERMAL_BOXLINE_CROSS_DOUBLE;
			else if(target == L'┼')
				return THERMAL_BOXLINE_CROSS_LIGHT;
			else if(target == L'▁')
				return THERMAL_BOXFILL_LOWER_EIGHTH;
			else if(target == L'▂')
				return THERMAL_BOXFILL_LOWER_QUARTER;
			else if(target == L'▃')
				return THERMAL_BOXFILL_LOWER_3EIGHTH;
			else if(target == L'▄')
				return THERMAL_BOXFILL_LOWER_HALF;
			else if(target == L'▆')
				return THERMAL_BOXFILL_LOWER_5EIGHTH;
			else if(target == L'▇')
				return THERMAL_BOXFILL_LOWER_3QUARTER;
			else if(target == L'█')
				return THERMAL_BOXFILL_LOWER_7EIGHTH;
			else if(target == L'▉')
				return THERMAL_BOXFILL_FULL;
			else if(target == L'▊')
				return THERMAL_BOXFILL_LEFT_7EIGHTH;
			else if(target == L'▋')
				return THERMAL_BOXFILL_LEFT_3QUARTER;
			else if(target == L'▌')
				return THERMAL_BOXFILL_LEFT_5EIGHTH;
			else if(target == L'▍')
				return THERMAL_BOXFILL_LEFT_HALF;
			else if(target == L'▎')
				return THERMAL_BOXFILL_LEFT_3EIGHTH;
			else if(target == L'▏')
				return THERMAL_BOXFILL_LEFT_EIGHTH;
			else if(target == L'▐')
				return THERMAL_BOXFILL_RIGHT_HALF;
			else if(target == L'░')
				return THERMAL_BOXFILL_SHADE_LIGHT;
			else if(target == L'▒')
				return THERMAL_BOXFILL_SHADE_MEDIUM;
			else if(target == L'▓')
				return THERMAL_BOXFILL_SHADE_DARK;
			else if(target == L'▔')
				return THERMAL_BOXFILL_UPPER_EIGHTH;
			else if(target == L'▕')
				return THERMAL_BOXFILL_RIGHT_EIGHTH;
			else if(target == L'▖')
				return THERMAL_BOXFILL_QUAD_LEFT_LOWER;
			else if(target == L'▗')
				return THERMAL_BOXFILL_QUAD_RIGHT_LOWER;
			else if(target == L'▘')
				return THERMAL_BOXFILL_QUAD_LEFT_UPPER;
			else if(target == L'▙')
				return THERMAL_BOXFILL_QUAD_NO_RIGHT_TOP;
			else if(target == L'▚')
				return THERMAL_BOXFILL_QUAD_LEFT_DIAG;
			else if(target == L'▛')
				return THERMAL_BOXFILL_QUAD_NO_RIGHT_BOTTOM;
			else if(target == L'▜')
				return THERMAL_BOXFILL_QUAD_NO_LEFT_BOTTOM;
			else if(target == L'▝')
				return THERMAL_BOXFILL_QUAD_RIGHT_UPPER;
			else if(target == L'▞')
				return THERMAL_BOXFILL_QUAD_RIGHT_DIAG;
			else if(target == L'▟')
				return THERMAL_BOXFILL_QUAD_NO_LEFT_TOP;
			else if(target == L'▀')
				return THERMAL_BOXFILL_UPPER_HALF;
			else if(target == L' ')
				return THERMAL_BOXELEMENT_EMPTY;
			else if(target == L'╲')
				return THERMAL_BOXLINE_MISC_BACKSLASH;
			else if(target == L'╳')
				return THERMAL_BOXLINE_MISC_X;
			else if(target == L'╱')
				return THERMAL_BOXLINE_MISC_FORWARDSLASH;
			return -1;	
		} // TODO: delete this comment
	
		bool generateBoxDarkSolid(void){
			if(!this->validateCornerPositions()){
				return false;
			}

			for(int i=0; i<this->data.data_size; i++){
				if(i == this->data.pos_corner_top_left){
					this->data.data[i] = this->cornerLine(THERMAL_BOXLINE_CORNER_TL_DARK);
				}else if(i == this->data.pos_corner_top_right){
					this->data.data[i] = this->cornerLine(THERMAL_BOXLINE_CORNER_TR_DARK);
				}else if(i == this->data.pos_corner_bottom_left){
					this->data.data[i] = this->cornerLine(THERMAL_BOXLINE_CORNER_BL_DARK);
				}else if(i == this->data.pos_corner_bottom_right){
					this->data.data[i] = this->cornerLine(THERMAL_BOXLINE_CORNER_BR_DARK);
				}else if(this->positionIsVertical(i)){
					this->data.data[i] = this->verticalLine(THERMAL_BOXLINE_VER_DARK);
				}else if(this->positionIsHorizontal(i)){
					this->data.data[i] = this->horizontalLine(THERMAL_BOXLINE_HOR_DARK);
				}else{ // it's a body position
					this->data.data[i] = this->blockFill(this->data.fill); 
				}
			}

			return true;
		}
		bool generateBoxLight3Dot(void){
			if(!this->validateCornerPositions()){
				return false;
			}

			for(int i=0; i<this->data.data_size; i++){
				if(i == this->data.pos_corner_top_left){
					this->data.data[i] = this->cornerLine(THERMAL_BOXLINE_CORNER_TL_LIGHT);
				}else if(i == this->data.pos_corner_top_right){
					this->data.data[i] = this->cornerLine(THERMAL_BOXLINE_CORNER_TR_LIGHT);
				}else if(i == this->data.pos_corner_bottom_left){
					this->data.data[i] = this->cornerLine(THERMAL_BOXLINE_CORNER_BL_LIGHT);
				}else if(i == this->data.pos_corner_bottom_right){
					this->data.data[i] = this->cornerLine(THERMAL_BOXLINE_CORNER_BR_LIGHT);
				}else if(this->positionIsVertical(i)){
					this->data.data[i] = this->verticalLine(THERMAL_BOXLINE_VER_LIGHT3DOT);
				}else if(this->positionIsHorizontal(i)){
					this->data.data[i] = this->horizontalLine(THERMAL_BOXLINE_HOR_LIGHT3DOT);
				}else{ // it's a body position
					this->data.data[i] = this->blockFill(this->data.fill); 
				}
			}

			return true;
		}
		bool generateBoxDark3Dot(void){
			if(!this->validateCornerPositions()){
				return false;
			}
			
			for(int i=0; i<this->data.data_size; i++){
				if(i == this->data.pos_corner_top_left){
					this->data.data[i] = this->cornerLine(THERMAL_BOXLINE_CORNER_TL_DARK);
				}else if(i == this->data.pos_corner_top_right){
					this->data.data[i] = this->cornerLine(THERMAL_BOXLINE_CORNER_TR_DARK);
				}else if(i == this->data.pos_corner_bottom_left){
					this->data.data[i] = this->cornerLine(THERMAL_BOXLINE_CORNER_BL_DARK);
				}else if(i == this->data.pos_corner_bottom_right){
					this->data.data[i] = this->cornerLine(THERMAL_BOXLINE_CORNER_BR_DARK);
				}else if(this->positionIsVertical(i)){
					this->data.data[i] = this->verticalLine(THERMAL_BOXLINE_VER_DARK3DOT);
				}else if(this->positionIsHorizontal(i)){
					this->data.data[i] = this->horizontalLine(THERMAL_BOXLINE_HOR_DARK3DOT);
				}else{ // it's a body position
					this->data.data[i] = this->blockFill(this->data.fill); 
				}
			}

			return true;
		}
		bool generateBoxLight4Dot(void){
			if(!this->validateCornerPositions()){
				return false;
			}

			for(int i=0; i<this->data.data_size; i++){
				if(i == this->data.pos_corner_top_left){
					this->data.data[i] = this->cornerLine(THERMAL_BOXLINE_CORNER_TL_LIGHT);
				}else if(i == this->data.pos_corner_top_right){
					this->data.data[i] = this->cornerLine(THERMAL_BOXLINE_CORNER_TR_LIGHT);
				}else if(i == this->data.pos_corner_bottom_left){
					this->data.data[i] = this->cornerLine(THERMAL_BOXLINE_CORNER_BL_LIGHT);
				}else if(i == this->data.pos_corner_bottom_right){
					this->data.data[i] = this->cornerLine(THERMAL_BOXLINE_CORNER_BR_LIGHT);
				}else if(this->positionIsVertical(i)){
					this->data.data[i] = this->verticalLine(THERMAL_BOXLINE_VER_LIGHT4DOT);
				}else if(this->positionIsHorizontal(i)){
					this->data.data[i] = this->horizontalLine(THERMAL_BOXLINE_HOR_LIGHT4DOT);
				}else{ // it's a body position
					this->data.data[i] = this->blockFill(this->data.fill); 
				}
			}

			return true;
		}
		bool generateBoxDark4Dot(void){
			if(!this->validateCornerPositions()){
				return false;
			}

			for(int i=0; i<this->data.data_size; i++){
				if(i == this->data.pos_corner_top_left){
					this->data.data[i] = this->cornerLine(THERMAL_BOXLINE_CORNER_TL_DARK);
				}else if(i == this->data.pos_corner_top_right){
					this->data.data[i] = this->cornerLine(THERMAL_BOXLINE_CORNER_TR_DARK);
				}else if(i == this->data.pos_corner_bottom_left){
					this->data.data[i] = this->cornerLine(THERMAL_BOXLINE_CORNER_BL_DARK);
				}else if(i == this->data.pos_corner_bottom_right){
					this->data.data[i] = this->cornerLine(THERMAL_BOXLINE_CORNER_BR_DARK);
				}else if(this->positionIsVertical(i)){
					this->data.data[i] = this->verticalLine(THERMAL_BOXLINE_VER_DARK4DOT);
				}else if(this->positionIsHorizontal(i)){
					this->data.data[i] = this->horizontalLine(THERMAL_BOXLINE_HOR_DARK4DOT);
				}else{ // it's a body position
					this->data.data[i] = this->blockFill(this->data.fill); 
				}
			}

			return true;
		}
		bool generateBoxDoubleLine(void){
			if(!this->validateCornerPositions()){
				return false;
			}

			for(int i=0; i<this->data.data_size; i++){
				if(i == this->data.pos_corner_top_left){
					this->data.data[i] = this->cornerLine(THERMAL_BOXLINE_CORNER_TL_DOUBLE);
				}else if(i == this->data.pos_corner_top_right){
					this->data.data[i] = this->cornerLine(THERMAL_BOXLINE_CORNER_TR_DOUBLE);
				}else if(i == this->data.pos_corner_bottom_left){
					this->data.data[i] = this->cornerLine(THERMAL_BOXLINE_CORNER_BL_DOUBLE);
				}else if(i == this->data.pos_corner_bottom_right){
					this->data.data[i] = this->cornerLine(THERMAL_BOXLINE_CORNER_BR_DOUBLE);
				}else if(this->positionIsVertical(i)){
					this->data.data[i] = this->verticalLine(THERMAL_BOXLINE_VER_DOUBLELINE);
				}else if(this->positionIsHorizontal(i)){
					this->data.data[i] = this->horizontalLine(THERMAL_BOXLINE_HOR_DOUBLELINE);
				}else{ // it's a body position
					this->data.data[i] = this->blockFill(this->data.fill); 
				}
			}

			return true;
		}
		bool generateBoxLight2Dot(void){
			if(!this->validateCornerPositions()){
				return false;
			}

			for(int i=0; i<this->data.data_size; i++){
				if(i == this->data.pos_corner_top_left){
					this->data.data[i] = this->cornerLine(THERMAL_BOXLINE_CORNER_TL_LIGHT);
				}else if(i == this->data.pos_corner_top_right){
					this->data.data[i] = this->cornerLine(THERMAL_BOXLINE_CORNER_TR_LIGHT);
				}else if(i == this->data.pos_corner_bottom_left){
					this->data.data[i] = this->cornerLine(THERMAL_BOXLINE_CORNER_BL_LIGHT);
				}else if(i == this->data.pos_corner_bottom_right){
					this->data.data[i] = this->cornerLine(THERMAL_BOXLINE_CORNER_BR_LIGHT);
				}else if(this->positionIsVertical(i)){
					this->data.data[i] = this->verticalLine(THERMAL_BOXLINE_VER_LIGHT2DOT);
				}else if(this->positionIsHorizontal(i)){
					this->data.data[i] = this->horizontalLine(THERMAL_BOXLINE_HOR_LIGHT2DOT);
				}else{ // it's a body position
					this->data.data[i] = this->blockFill(this->data.fill); 
				}
			}

			return true;
		}
		bool generateBoxDark2Dot(void){
			if(!this->validateCornerPositions()){
				return false;
			}

			for(int i=0; i<this->data.data_size; i++){
				if(i == this->data.pos_corner_top_left){
					this->data.data[i] = this->cornerLine(THERMAL_BOXLINE_CORNER_TL_DARK);
				}else if(i == this->data.pos_corner_top_right){
					this->data.data[i] = this->cornerLine(THERMAL_BOXLINE_CORNER_TR_DARK);
				}else if(i == this->data.pos_corner_bottom_left){
					this->data.data[i] = this->cornerLine(THERMAL_BOXLINE_CORNER_BL_DARK);
				}else if(i == this->data.pos_corner_bottom_right){
					this->data.data[i] = this->cornerLine(THERMAL_BOXLINE_CORNER_BR_DARK);
				}else if(this->positionIsVertical(i)){
					this->data.data[i] = this->verticalLine(THERMAL_BOXLINE_VER_DARK2DOT);
				}else if(this->positionIsHorizontal(i)){
					this->data.data[i] = this->horizontalLine(THERMAL_BOXLINE_HOR_DARK2DOT);
				}else{ // it's a body position
					this->data.data[i] = this->blockFill(this->data.fill); 
				}
			}

			return true;
		}
		bool generateBoxLightSolid(void){
			if(!this->validateCornerPositions()){
				return false;
			}

			for(int i=0; i<this->data.data_size; i++){
				if(i == this->data.pos_corner_top_left){
					this->data.data[i] = this->cornerLine(THERMAL_BOXLINE_CORNER_TL_LIGHT);
				}else if(i == this->data.pos_corner_top_right){
					this->data.data[i] = this->cornerLine(THERMAL_BOXLINE_CORNER_TR_LIGHT);
				}else if(i == this->data.pos_corner_bottom_left){
					this->data.data[i] = this->cornerLine(THERMAL_BOXLINE_CORNER_BL_LIGHT);
				}else if(i == this->data.pos_corner_bottom_right){
					this->data.data[i] = this->cornerLine(THERMAL_BOXLINE_CORNER_BR_LIGHT);
				}else if(this->positionIsVertical(i)){
					this->data.data[i] = this->verticalLine(THERMAL_BOXLINE_VER_LIGHT);
				}else if(this->positionIsHorizontal(i)){
					this->data.data[i] = this->horizontalLine(THERMAL_BOXLINE_HOR_LIGHT);
				}else{ // it's a body position
					this->data.data[i] = this->blockFill(this->data.fill); 
				}
			}

			return true;
		}
		
		bool generateBoxData(void){
			if(!this->validateCornerPositions()){
				return false;
			}

			for(int i=0; i<this->data.data_size; i++){
				if(i == this->data.pos_corner_top_left){
					this->data.data[i] = this->cornerLine(this->data.corner_top_left);
				}else if(i == this->data.pos_corner_top_right){
					this->data.data[i] = this->cornerLine(this->data.corner_top_right);
				}else if(i == this->data.pos_corner_bottom_left){
					this->data.data[i] = this->cornerLine(this->data.corner_bottom_left);
				}else if(i == this->data.pos_corner_bottom_right){
					this->data.data[i] = this->cornerLine(this->data.corner_bottom_right);
				}else if(this->positionIsVertical(i)){
					this->data.data[i] = this->verticalLine(this->data.edge_left);
				}else if(this->positionIsHorizontal(i)){
					this->data.data[i] = this->horizontalLine(this->data.edge_top);
				}else{ // it's a body position
					this->data.data[i] = this->blockFill(this->data.fill); 
				}
			}

			return true;
		}

		bool mapString(int x, int y, std::string str){
			if(this->data.data == NULL || this->data.data_size <= 0) return false;
			int str_s = str.length();
			if(str_s <= 0) return true;

			int w = this->data.width;
			int h = this->data.height;
			wchar_t *dst = this->data.data;
			size_t dst_s = this->data.data_size;

			if(x >= w) return true;
			if((x+str_s) < 0) return true;
			if(y < 0 || y >= h) return true;

			int stringOffset = (x < 0) ? str_s - (-1 * x) : 0;
			int injectionPosition = (y * w) + ((stringOffset == 0) ? x : 0);
			
			for(int i=injectionPosition, s=0; i<dst_s && s<str_s; i++, s++){
				if((i%(w+1)) == w) break;
				dst[i] = (wchar_t)str[s];
			}
			
			return true;
		}

		bool macroIsCorner(int target){	
			if((target & THERMAL_MASK_BORDERTYPE) == THERMAL_BOXLINE_CORNER)
				return true;
			return false;
		}

		bool macroIsHorizontal(int target){
			if((target & THERMAL_MASK_BORDERTYPE) == THERMAL_BOXLINE_HOR)
				return true;
			return false;
		}
		
		bool macroIsVertical(int target){
			if((target & THERMAL_MASK_BORDERTYPE) == THERMAL_BOXLINE_VER)
				return true;
			return false;
		}

		bool cellIsRightwardLinked(int macroTarget){
			switch(macroTarget){
				case THERMAL_BOXLINE_HOR_DARK:
				case THERMAL_BOXLINE_HOR_LIGHT3DOT:
				case THERMAL_BOXLINE_HOR_DARK3DOT:
				case THERMAL_BOXLINE_HOR_LIGHT4DOT:
				case THERMAL_BOXLINE_HOR_DARK4DOT:
				case THERMAL_BOXLINE_HOR_DOUBLELINE:
				case THERMAL_BOXLINE_HOR_LIGHT2DOT:
				case THERMAL_BOXLINE_HOR_DARK2DOT:
				case THERMAL_BOXLINE_HOR_LIGHTLEFT:
				case THERMAL_BOXLINE_HOR_DARKLEFT:
				case THERMAL_BOXLINE_HOR_TEARLEFT:
				case THERMAL_BOXLINE_HOR_LIGHT:
				case THERMAL_BOXLINE_CORNER_TL_LVERDHOR:
				case THERMAL_BOXLINE_CORNER_TL_DVERLHOR:
				case THERMAL_BOXLINE_CORNER_TL_DARK:
				case THERMAL_BOXLINE_CORNER_BL_LIGHT:
				case THERMAL_BOXLINE_CORNER_BL_LVERDHOR:
				case THERMAL_BOXLINE_CORNER_BL_DVERLHOR:
				case THERMAL_BOXLINE_CORNER_BL_DARK:
				case THERMAL_BOXLINE_CORNER_TL_1VER2HOR:
				case THERMAL_BOXLINE_CORNER_TL_2VER1HOR:
				case THERMAL_BOXLINE_CORNER_TL_DOUBLE:
				case THERMAL_BOXLINE_CORNER_BL_1VER2HOR:
				case THERMAL_BOXLINE_CORNER_BL_2VER1HOR:
				case THERMAL_BOXLINE_CORNER_BL_DOUBLE:
				case THERMAL_BOXLINE_CORNER_TL_ROUND:
				case THERMAL_BOXLINE_CORNER_BL_ROUND:
				case THERMAL_BOXLINE_CORNER_TL_LIGHT:
				case THERMAL_BOXLINE_T_LEFT_LIGHT_RD:
				case THERMAL_BOXLINE_T_LEFT_LIGHT_TD:
				case THERMAL_BOXLINE_T_LEFT_LGHT_BD:
				case THERMAL_BOXLINE_T_LEFT_DARK_RL:
				case THERMAL_BOXLINE_T_LEFT_DARK_BL:
				case THERMAL_BOXLINE_T_LEFT_DARK_TL:
				case THERMAL_BOXLINE_T_LEFT_DARK:
				case THERMAL_BOXLINE_T_TOP_LIGHT:
				case THERMAL_BOXLINE_T_TOP_LIGHT_LD:
				case THERMAL_BOXLINE_T_TOP_LIGHT_RD:
				case THERMAL_BOXLINE_T_TOP_TD_BL:
				case THERMAL_BOXLINE_T_TOP_TL_BD:
				case THERMAL_BOXLINE_T_TOP_DARK_RL:
				case THERMAL_BOXLINE_T_TOP_DARK_LL:
				case THERMAL_BOXLINE_T_TOP_DARK:
				case THERMAL_BOXLINE_T_BOTTOM_LIGHT:
				case THERMAL_BOXLINE_T_BOTTOM_LIGHT_LD:
				case THERMAL_BOXLINE_T_BOTTOM_LUIGHT_RD:
				case THERMAL_BOXLINE_T_BOTTOM_TL_BD:
				case THERMAL_BOXLINE_T_BOTTOM_TD_BL:
				case THERMAL_BOXLINE_T_BOTTOM_DARK_RL:
				case THERMAL_BOXLINE_T_BOTTOM_DARK_LL:
				case THERMAL_BOXLINE_T_BOTTOM_DARK:
				case THERMAL_BOXLINE_T_LEFT_LL_RDUB:
				case THERMAL_BOXLINE_T_LEFT_LDUB_RL:
				case THERMAL_BOXLINE_T_LEFT_DOUBLE:
				case THERMAL_BOXLINE_T_TOP_TDUB_BL:
				case THERMAL_BOXLINE_T_TOP_TL_BDUB:
				case THERMAL_BOXLINE_T_TOP_DOUBLE:
				case THERMAL_BOXLINE_T_BOTTOM_TL_BDUB:
				case THERMAL_BOXLINE_T_BOTTOM_TDUB_BL:
				case THERMAL_BOXLINE_T_BOTTOM_DOUBLE:
				case THERMAL_BOXLINE_CROSS_LIGHT_LD:
				case THERMAL_BOXLINE_CROSS_LIGHT_RD:
				case THERMAL_BOXLINE_CROSS_LIGHT_HD:
				case THERMAL_BOXLINE_CROSS_LIGHT_TD:
				case THERMAL_BOXLINE_CROSS_LIGHT_BD:
				case THERMAL_BOXLINE_CROSS_LIGHT_VD:
				case THERMAL_BOXLINE_CROSS_LIGHTBR_DARKTL:
				case THERMAL_BOXLINE_CROSS_LIGHTBL_DARKTR:
				case THERMAL_BOXLINE_CROSS_LIGHTTL_DARKBR:
				case THERMAL_BOXLINE_CROSS_LIGHTTR_DARK_BL:
				case THERMAL_BOXLINE_CROSS_DARK_BL:
				case THERMAL_BOXLINE_CROSS_DARK_TL:
				case THERMAL_BOXLINE_CROSS_DARK_RL:
				case THERMAL_BOXLINE_CROSS_DARK_LL:
				case THERMAL_BOXLINE_CROSS_DARK:
				case THERMAL_BOXLINE_CROSS_LIGHT_DUBHOR:
				case THERMAL_BOXLINE_CROSS_LIGHT_DUBVER:
				case THERMAL_BOXLINE_CROSS_DOUBLE:
				case THERMAL_BOXLINE_CROSS_LIGHT:
				return true;
			}
			return false;
		}
		bool cellIsLeftwardLinked(int macroTarget){
			switch(macroTarget){
				case THERMAL_BOXLINE_HOR_DARK:
				case THERMAL_BOXLINE_HOR_LIGHT3DOT:
				case THERMAL_BOXLINE_HOR_DARK3DOT:
				case THERMAL_BOXLINE_HOR_LIGHT4DOT:
				case THERMAL_BOXLINE_HOR_DARK4DOT:
				case THERMAL_BOXLINE_HOR_DOUBLELINE:
				case THERMAL_BOXLINE_HOR_LIGHT2DOT:
				case THERMAL_BOXLINE_HOR_DARK2DOT:
				case THERMAL_BOXLINE_HOR_LIGHTLEFT:
				case THERMAL_BOXLINE_HOR_LIGHTRIGHT:
				case THERMAL_BOXLINE_HOR_DARKLEFT:
				case THERMAL_BOXLINE_HOR_DARKRIGHT:
				case THERMAL_BOXLINE_HOR_TEARRIGHT:
				case THERMAL_BOXLINE_HOR_TEARLEFT:
				case THERMAL_BOXLINE_HOR_LIGHT:
				case THERMAL_BOXLINE_CORNER_TR_LIGHT:
				case THERMAL_BOXLINE_CORNER_TR_LVERDHOR:
				case THERMAL_BOXLINE_CORNER_TR_DVERLHOR:
				case THERMAL_BOXLINE_CORNER_TR_DARK:
				case THERMAL_BOXLINE_CORNER_BR_LIGHT:
				case THERMAL_BOXLINE_CORNER_BR_LVERDHOR:
				case THERMAL_BOXLINE_CORNER_BR_DVERLHOR:
				case THERMAL_BOXLINE_CORNER_BR_DARK:
				case THERMAL_BOXLINE_CORNER_TR_1VER_2HOR:
				case THERMAL_BOXLINE_CORNER_TR_2VER1HOR:
				case THERMAL_BOXLINE_CORNER_TR_DOUBLE:
				case THERMAL_BOXLINE_CORNER_BR_1VER2HOR:
				case THERMAL_BOXLINE_CORNER_BR_2VER1HOR:
				case THERMAL_BOXLINE_CORNER_BR_DOUBLE:
				case THERMAL_BOXLINE_CORNER_TR_ROUND:
				case THERMAL_BOXLINE_CORNER_BR_ROUND:
				case THERMAL_BOXLINE_T_LEFT_LIGHT_RD:
				case THERMAL_BOXLINE_T_RIGHT_LIGHT:
				case THERMAL_BOXLINE_T_RIGHT_LIGHT_LD:
				case THERMAL_BOXLINE_T_RIGHT_LIGHT_TD:
				case THERMAL_BOXLINE_T_RIGHT_LIGHT_BD:
				case THERMAL_BOXLINE_T_RIGHT_DARK_LL:
				case THERMAL_BOXLINE_T_RIGHT_DARK_BL:
				case THERMAL_BOXLINE_T_RIGHT_DARK_TL:
				case THERMAL_BOXLINE_T_RIGHT_DARK:
				case THERMAL_BOXLINE_T_TOP_LIGHT:
				case THERMAL_BOXLINE_T_TOP_LIGHT_LD:
				case THERMAL_BOXLINE_T_TOP_LIGHT_RD:
				case THERMAL_BOXLINE_T_TOP_TD_BL:
				case THERMAL_BOXLINE_T_TOP_TL_BD:
				case THERMAL_BOXLINE_T_TOP_DARK_RL:
				case THERMAL_BOXLINE_T_TOP_DARK_LL:
				case THERMAL_BOXLINE_T_TOP_DARK:
				case THERMAL_BOXLINE_T_BOTTOM_LIGHT:
				case THERMAL_BOXLINE_T_BOTTOM_LIGHT_LD:
				case THERMAL_BOXLINE_T_BOTTOM_LUIGHT_RD:
				case THERMAL_BOXLINE_T_BOTTOM_TL_BD:
				case THERMAL_BOXLINE_T_BOTTOM_TD_BL:
				case THERMAL_BOXLINE_T_BOTTOM_DARK_RL:
				case THERMAL_BOXLINE_T_BOTTOM_DARK_LL:
				case THERMAL_BOXLINE_T_BOTTOM_DARK:
				case THERMAL_BOXLINE_T_RIGHT_LDUB_RL:
				case THERMAL_BOXLINE_T_RIGHT_LL_RDUB:
				case THERMAL_BOXLINE_T_RIGHT_DOUBLE:
				case THERMAL_BOXLINE_T_TOP_TDUB_BL:
				case THERMAL_BOXLINE_T_TOP_TL_BDUB:
				case THERMAL_BOXLINE_T_TOP_DOUBLE:
				case THERMAL_BOXLINE_T_BOTTOM_TL_BDUB:
				case THERMAL_BOXLINE_T_BOTTOM_TDUB_BL:
				case THERMAL_BOXLINE_T_BOTTOM_DOUBLE:
				case THERMAL_BOXLINE_CROSS_LIGHT_LD:
				case THERMAL_BOXLINE_CROSS_LIGHT_RD:
				case THERMAL_BOXLINE_CROSS_LIGHT_HD:
				case THERMAL_BOXLINE_CROSS_LIGHT_TD:
				case THERMAL_BOXLINE_CROSS_LIGHT_BD:
				case THERMAL_BOXLINE_CROSS_LIGHT_VD:
				case THERMAL_BOXLINE_CROSS_LIGHTBR_DARKTL:
				case THERMAL_BOXLINE_CROSS_LIGHTBL_DARKTR:
				case THERMAL_BOXLINE_CROSS_LIGHTTL_DARKBR:
				case THERMAL_BOXLINE_CROSS_LIGHTTR_DARK_BL:
				case THERMAL_BOXLINE_CROSS_DARK_BL:
				case THERMAL_BOXLINE_CROSS_DARK_TL:
				case THERMAL_BOXLINE_CROSS_DARK_RL:
				case THERMAL_BOXLINE_CROSS_DARK_LL:
				case THERMAL_BOXLINE_CROSS_DARK:
				case THERMAL_BOXLINE_CROSS_LIGHT_DUBHOR:
				case THERMAL_BOXLINE_CROSS_LIGHT_DUBVER:
				case THERMAL_BOXLINE_CROSS_DOUBLE:
				case THERMAL_BOXLINE_CROSS_LIGHT:
					return true;
			}
			return false;
		}
		bool cellIsDownwardLinked(int macroTarget){
			switch(macroTarget){
				case THERMAL_BOXLINE_VER_DARK:
				case THERMAL_BOXLINE_VER_LIGHT3DOT:
				case THERMAL_BOXLINE_VER_DARK3DOT:
				case THERMAL_BOXLINE_VER_LIGHT4DOT:
				case THERMAL_BOXLINE_VER_DARK4DOT:
				case THERMAL_BOXLINE_VER_LIGHT2DOT:
				case THERMAL_BOXLINE_VER_DARK2DOT:
				case THERMAL_BOXLINE_VER_DOUBLELINE:
				case THERMAL_BOXLINE_VER_LIGHTTOP:
				case THERMAL_BOXLINE_VER_LIGHTBOTTOM:
				case THERMAL_BOXLINE_VER_DARKTOP:
				case THERMAL_BOXLINE_VER_DARK_BOTTOM:
				case THERMAL_BOXLINE_VER_TEARDOWN:
				case THERMAL_BOXLINE_VER_TEARUP:
				case THERMAL_BOXLINE_VER_LIGHT:
				case THERMAL_BOXLINE_CORNER_TL_LVERDHOR:
				case THERMAL_BOXLINE_CORNER_TL_DVERLHOR:
				case THERMAL_BOXLINE_CORNER_TL_DARK:
				case THERMAL_BOXLINE_CORNER_TR_LIGHT:
				case THERMAL_BOXLINE_CORNER_TR_LVERDHOR:
				case THERMAL_BOXLINE_CORNER_TR_DVERLHOR:
				case THERMAL_BOXLINE_CORNER_TR_DARK:
				case THERMAL_BOXLINE_CORNER_TL_1VER2HOR:
				case THERMAL_BOXLINE_CORNER_TL_2VER1HOR:
				case THERMAL_BOXLINE_CORNER_TL_DOUBLE:
				case THERMAL_BOXLINE_CORNER_TR_1VER_2HOR:
				case THERMAL_BOXLINE_CORNER_TR_2VER1HOR:
				case THERMAL_BOXLINE_CORNER_TR_DOUBLE:
				case THERMAL_BOXLINE_CORNER_TL_ROUND:
				case THERMAL_BOXLINE_CORNER_TR_ROUND:
				case THERMAL_BOXLINE_CORNER_TL_LIGHT:
				case THERMAL_BOXLINE_T_LEFT_LIGHT_RD:
				case THERMAL_BOXLINE_T_LEFT_LIGHT_TD:
				case THERMAL_BOXLINE_T_LEFT_LGHT_BD:
				case THERMAL_BOXLINE_T_LEFT_DARK_RL:
				case THERMAL_BOXLINE_T_LEFT_DARK_BL:
				case THERMAL_BOXLINE_T_LEFT_DARK_TL:
				case THERMAL_BOXLINE_T_LEFT_DARK:
				case THERMAL_BOXLINE_T_RIGHT_LIGHT:
				case THERMAL_BOXLINE_T_RIGHT_LIGHT_LD:
				case THERMAL_BOXLINE_T_RIGHT_LIGHT_TD:
				case THERMAL_BOXLINE_T_RIGHT_LIGHT_BD:
				case THERMAL_BOXLINE_T_RIGHT_DARK_LL:
				case THERMAL_BOXLINE_T_RIGHT_DARK_BL:
				case THERMAL_BOXLINE_T_RIGHT_DARK_TL:
				case THERMAL_BOXLINE_T_RIGHT_DARK:
				case THERMAL_BOXLINE_T_TOP_LIGHT:
				case THERMAL_BOXLINE_T_TOP_LIGHT_LD:
				case THERMAL_BOXLINE_T_TOP_LIGHT_RD:
				case THERMAL_BOXLINE_T_TOP_TD_BL:
				case THERMAL_BOXLINE_T_TOP_TL_BD:
				case THERMAL_BOXLINE_T_TOP_DARK_RL:
				case THERMAL_BOXLINE_T_TOP_DARK_LL:
				case THERMAL_BOXLINE_T_TOP_DARK:
				case THERMAL_BOXLINE_T_LEFT_LL_RDUB:
				case THERMAL_BOXLINE_T_LEFT_LDUB_RL:
				case THERMAL_BOXLINE_T_LEFT_DOUBLE:
				case THERMAL_BOXLINE_T_RIGHT_LDUB_RL:
				case THERMAL_BOXLINE_T_RIGHT_LL_RDUB:
				case THERMAL_BOXLINE_T_RIGHT_DOUBLE:
				case THERMAL_BOXLINE_T_TOP_TDUB_BL:
				case THERMAL_BOXLINE_T_TOP_TL_BDUB:
				case THERMAL_BOXLINE_T_TOP_DOUBLE:
				case THERMAL_BOXLINE_T_LEFT_LIGHT:
				case THERMAL_BOXLINE_CROSS_LIGHT_LD:
				case THERMAL_BOXLINE_CROSS_LIGHT_RD:
				case THERMAL_BOXLINE_CROSS_LIGHT_HD:
				case THERMAL_BOXLINE_CROSS_LIGHT_TD:
				case THERMAL_BOXLINE_CROSS_LIGHT_BD:
				case THERMAL_BOXLINE_CROSS_LIGHT_VD:
				case THERMAL_BOXLINE_CROSS_LIGHTBR_DARKTL:
				case THERMAL_BOXLINE_CROSS_LIGHTBL_DARKTR:
				case THERMAL_BOXLINE_CROSS_LIGHTTL_DARKBR:
				case THERMAL_BOXLINE_CROSS_LIGHTTR_DARK_BL:
				case THERMAL_BOXLINE_CROSS_DARK_BL:
				case THERMAL_BOXLINE_CROSS_DARK_TL:
				case THERMAL_BOXLINE_CROSS_DARK_RL:
				case THERMAL_BOXLINE_CROSS_DARK_LL:
				case THERMAL_BOXLINE_CROSS_DARK:
				case THERMAL_BOXLINE_CROSS_LIGHT_DUBHOR:
				case THERMAL_BOXLINE_CROSS_LIGHT_DUBVER:
				case THERMAL_BOXLINE_CROSS_DOUBLE:
				case THERMAL_BOXLINE_CROSS_LIGHT:
					return true;
			}
			return false;
		}
		bool cellIsUpwardLinked(int macroTarget){
			switch(macroTarget){
				case THERMAL_BOXLINE_VER_DARK:
				case THERMAL_BOXLINE_VER_LIGHT3DOT:
				case THERMAL_BOXLINE_VER_DARK3DOT:
				case THERMAL_BOXLINE_VER_LIGHT4DOT:
				case THERMAL_BOXLINE_VER_DARK4DOT:
				case THERMAL_BOXLINE_VER_LIGHT2DOT:
				case THERMAL_BOXLINE_VER_DARK2DOT:
				case THERMAL_BOXLINE_VER_DOUBLELINE:
				case THERMAL_BOXLINE_VER_LIGHTTOP:
				case THERMAL_BOXLINE_VER_LIGHTBOTTOM:
				case THERMAL_BOXLINE_VER_DARKTOP:
				case THERMAL_BOXLINE_VER_DARK_BOTTOM:
				case THERMAL_BOXLINE_VER_TEARDOWN:
				case THERMAL_BOXLINE_VER_TEARUP:
				case THERMAL_BOXLINE_VER_LIGHT:
				case THERMAL_BOXLINE_CORNER_BL_LIGHT:
				case THERMAL_BOXLINE_CORNER_BL_LVERDHOR:
				case THERMAL_BOXLINE_CORNER_BL_DVERLHOR:
				case THERMAL_BOXLINE_CORNER_BL_DARK:
				case THERMAL_BOXLINE_CORNER_BR_LIGHT:
				case THERMAL_BOXLINE_CORNER_BR_LVERDHOR:
				case THERMAL_BOXLINE_CORNER_BR_DVERLHOR:
				case THERMAL_BOXLINE_CORNER_BR_DARK:
				case THERMAL_BOXLINE_CORNER_BL_1VER2HOR:
				case THERMAL_BOXLINE_CORNER_BL_2VER1HOR:
				case THERMAL_BOXLINE_CORNER_BL_DOUBLE:
				case THERMAL_BOXLINE_CORNER_BR_1VER2HOR:
				case THERMAL_BOXLINE_CORNER_BR_2VER1HOR:
				case THERMAL_BOXLINE_CORNER_BR_DOUBLE:
				case THERMAL_BOXLINE_CORNER_BR_ROUND:
				case THERMAL_BOXLINE_CORNER_BL_ROUND:
				case THERMAL_BOXLINE_T_LEFT_LIGHT_RD:
				case THERMAL_BOXLINE_T_LEFT_LIGHT_TD:
				case THERMAL_BOXLINE_T_LEFT_LGHT_BD:
				case THERMAL_BOXLINE_T_LEFT_DARK_RL:
				case THERMAL_BOXLINE_T_LEFT_DARK_BL:
				case THERMAL_BOXLINE_T_LEFT_DARK_TL:
				case THERMAL_BOXLINE_T_LEFT_DARK:
				case THERMAL_BOXLINE_T_RIGHT_LIGHT:
				case THERMAL_BOXLINE_T_RIGHT_LIGHT_LD:
				case THERMAL_BOXLINE_T_RIGHT_LIGHT_TD:
				case THERMAL_BOXLINE_T_RIGHT_LIGHT_BD:
				case THERMAL_BOXLINE_T_RIGHT_DARK_LL:
				case THERMAL_BOXLINE_T_RIGHT_DARK_BL:
				case THERMAL_BOXLINE_T_RIGHT_DARK_TL:
				case THERMAL_BOXLINE_T_RIGHT_DARK:
				case THERMAL_BOXLINE_T_BOTTOM_LIGHT:
				case THERMAL_BOXLINE_T_BOTTOM_LIGHT_LD:
				case THERMAL_BOXLINE_T_BOTTOM_LUIGHT_RD:
				case THERMAL_BOXLINE_T_BOTTOM_TL_BD:
				case THERMAL_BOXLINE_T_BOTTOM_TD_BL:
				case THERMAL_BOXLINE_T_BOTTOM_DARK_RL:
				case THERMAL_BOXLINE_T_BOTTOM_DARK_LL:
				case THERMAL_BOXLINE_T_BOTTOM_DARK:
				case THERMAL_BOXLINE_T_LEFT_LL_RDUB:
				case THERMAL_BOXLINE_T_LEFT_LDUB_RL:
				case THERMAL_BOXLINE_T_LEFT_DOUBLE:
				case THERMAL_BOXLINE_T_RIGHT_LDUB_RL:
				case THERMAL_BOXLINE_T_RIGHT_LL_RDUB:
				case THERMAL_BOXLINE_T_RIGHT_DOUBLE:
				case THERMAL_BOXLINE_T_BOTTOM_TL_BDUB:
				case THERMAL_BOXLINE_T_BOTTOM_TDUB_BL:
				case THERMAL_BOXLINE_T_BOTTOM_DOUBLE:
				case THERMAL_BOXLINE_T_LEFT_LIGHT:
				case THERMAL_BOXLINE_CROSS_LIGHT_LD:
				case THERMAL_BOXLINE_CROSS_LIGHT_RD:
				case THERMAL_BOXLINE_CROSS_LIGHT_HD:
				case THERMAL_BOXLINE_CROSS_LIGHT_TD:
				case THERMAL_BOXLINE_CROSS_LIGHT_BD:
				case THERMAL_BOXLINE_CROSS_LIGHT_VD:
				case THERMAL_BOXLINE_CROSS_LIGHTBR_DARKTL:
				case THERMAL_BOXLINE_CROSS_LIGHTBL_DARKTR:
				case THERMAL_BOXLINE_CROSS_LIGHTTL_DARKBR:
				case THERMAL_BOXLINE_CROSS_LIGHTTR_DARK_BL:
				case THERMAL_BOXLINE_CROSS_DARK_BL:
				case THERMAL_BOXLINE_CROSS_DARK_TL:
				case THERMAL_BOXLINE_CROSS_DARK_RL:
				case THERMAL_BOXLINE_CROSS_DARK_LL:
				case THERMAL_BOXLINE_CROSS_DARK:
				case THERMAL_BOXLINE_CROSS_LIGHT_DUBHOR:
				case THERMAL_BOXLINE_CROSS_LIGHT_DUBVER:
				case THERMAL_BOXLINE_CROSS_DOUBLE:
				case THERMAL_BOXLINE_CROSS_LIGHT:
					return true;
			}
			return false;
		}

		int positionIsAtIntersect(int x, int y){
			int ret = THERMAL_INTERSECT_ERR;
			// Coords of the point to my left
			if(y <= 0 || y >= this->data.height) return ret;
			if(x <= 0 || x >= this->data.width) return ret;

			int a_x = x-1;
			int a_y = y;

			// Coords of the point to my right
			int b_x = x+1;
			int b_y = y;

			// Coords of the point above me
			int c_x = x;
			int c_y = y-1;

			// Coords of the point below me.
			int d_x = x;
			int d_y = y+1;

			// The actual buffer index from each coord.
			int i = x + (y * this->data.width);
			int ai = a_x + (a_y * this->data.width);
			int bi = b_x + (b_y * this->data.width);
			int ci = c_x + (c_y * this->data.width);
			int di = d_x + (d_y * this->data.width);
			ret = 0;
			
			bool isntRightward = true;
			bool isntLeftward = true;
			bool isntDownward = true;
			bool isntUpward = true;

			if(ai >= 0 && ai < this->data.data_size)
				isntRightward = (!this->cellIsRightwardLinked(this->getBorderMacro(this->data.data[ai])));
			if(bi >= 0 && bi < this->data.data_size)
				isntLeftward = (!this->cellIsLeftwardLinked(this->getBorderMacro(this->data.data[bi])));
			if(ci >= 0 && ci < this->data.data_size)
				isntDownward = (!this->cellIsDownwardLinked(this->getBorderMacro(this->data.data[ci])));
			if(di >= 0 && di < this->data.data_size)
				isntUpward = (!this->cellIsUpwardLinked(this->getBorderMacro(this->data.data[di])));

			if(isntRightward)
				ret += THERMAL_INTERSECT_ERR_RIGHT;
			if(isntLeftward)
				ret += THERMAL_INTERSECT_ERR_LEFT;
			if(isntDownward)
				ret += THERMAL_INTERSECT_ERR_DOWN;
			if(isntUpward)
				ret += THERMAL_INTERSECT_ERR_UP;

			return ret;
		}

		bool fuseByEdge(ThermalBox src, int edgeTarget, int originOffset){
			thermbox_t *srcData = src.getData();
			if(srcData == NULL) return false; 
			int srcLength = (edgeTarget == THERMAL_BOXEDGE_TOP || edgeTarget == THERMAL_BOXEDGE_BOTTOM) ? 
					srcData->width : (edgeTarget == THERMAL_BOXEDGE_RIGHT || edgeTarget == THERMAL_BOXEDGE_RIGHT) ? 
					srcData->height : 0;

			int dstLength = (edgeTarget == THERMAL_BOXEDGE_TOP || edgeTarget == THERMAL_BOXEDGE_BOTTOM) ? 
                                        this->data.width : (edgeTarget == THERMAL_BOXEDGE_RIGHT || edgeTarget == THERMAL_BOXEDGE_RIGHT) ? 
                                        this->data.height : 0;
			
			bool srcIsBigger = (srcLength > dstLength);
			
			// Reallocate the dst(current) box
			if(this->data.data_size <= 0 || this->data.data == NULL) 
				return false;
			if(srcData->data_size <= 0 || srcData->data == NULL)
				return false;
			size_t transferBuffSize = this->data.data_size;
			if(transferBuffSize <= 0) return false;
			wchar_t *transferBuff = new (std::nothrow) wchar_t[transferBuffSize];
			if(transferBuff == NULL) return false;
			for(int i=0; i>transferBuffSize; i++)
				transferBuff[i] = this->data.data[i];
			delete[] this->data.data;
		
			switch(edgeTarget){
				case THERMAL_BOXEDGE_TOP:{
					// Allocate Buffer
					this->data.data_size += srcData->height * this->data.width;
					this->data.data = new (std::nothrow) wchar_t[this->data.data_size];
					if(this->data.data == NULL) return false;
			
					// Reposition original data
					for(int j=0, i=srcData->height * this->data.width; j<transferBuffSize && i<this->data.data_size; i++, j++)
						this->data.data[i] = transferBuff[j];

					// Inject Src Box Into Empty Space
					for(int i=originOffset, j=0; i<this->data.data_size && j<srcData->data_size; i++, j++){
						int x = j % srcData->width;
						int y = j / srcData->width;
						int i_x = i % this->data.width;
						int i_y = i / this->data.width;
						if(y == srcData->height-1){ // border row
							int dstBorderType = this->getBorderMacro(this->data.data[i]);
							int srcBorderType = this->getBorderMacro(srcData->data[j]);
							int masterPos = positionIsAtIntersect(i_x, i_y);
						/*	
							if(this->macroIsCorner(dstBorderType)){
								if(this->macroIsCorner(srcBorderType)){
									
								}else if(this->macroIsHorizontal(srcBorderType)){
									
								}else if(this->macroIsVertical(srcBorderType)){

								}else{
									// unknown border type
								}
							}else if(this->macroIsHorizontal(dstBorderType)){
								if(this->macroIsCorner(srcBorderType)){

								}else if(this->macroIsHorizontal(srcBorderType)){
									
								}else if(this->macroIsVertical(srcBorderType)){

								}else{
									// unknown border type
								}
							}else if(this->macroIsVertical(dstBorderType)){
								if(this->macroIsCorner(srcBorderType)){

								}else if(this->macroIsHorizontal(srcBorderType)){

								}else if(this->macroIsVertical(srcBorderType)){

								}else{
									// unknown border type
								}
							}else{
								// unknown border type
							}*/
						}else{
							this->data.data[i] = srcData->data[j];
							if(((j+1) % srcData->width) == 0){
								i += this->data.width  - (i % this->data.width) - 1 + originOffset;
							}
						}
					}	
					break;
				}
				case THERMAL_BOXEDGE_BOTTOM:{
					// Allocate Buffer
					this->data.data_size += srcData->height * this->data.width;
					this->data.data = new (std::nothrow) wchar_t[this->data.data_size];
					if(this->data.data == NULL) return false;

					// Reposition original data
					for(int i=0, j=0; i<this->data.data_size && j < transferBuffSize; i++, j++)
						this->data.data[i] = transferBuff[j];

					// Inject Src Box Into Empty Space
					break;
				}
				case THERMAL_BOXEDGE_LEFT:{
					// Allocate Buffer
					this->data.data_size += srcData->width * this->data.height;
					this->data.data = new (std::nothrow) wchar_t[this->data.data_size];
					if(this->data.data == NULL) return false;

					// Reposition original data
					for(int j=0, i=srcData->width; i<this->data.data_size && j<transferBuffSize; j++, i++){
						this->data.data[i] = transferBuff[j];
						if(((i+1) % this->data.width) == 0){
							// next iteration is a new line.
							i+=srcData->width;
						}	
					}	

					// Inject Src Box Into Empty Space
					break;
				}
				case THERMAL_BOXEDGE_RIGHT:{
					// Allocate Buffer
					this->data.data_size += srcData->width * this->data.height;
					this->data.data = new (std::nothrow) wchar_t[this->data.data_size];
					if(this->data.data == NULL) return false;

					// Reposition original data
					for(int j=0, i=0; i<this->data.data_size && j<transferBuffSize; j++, i++){
						this->data.data[i] = transferBuff[j];
						if(((i+1) % this->data.width) == 0){
							i+=srcData->width;
						}
					}

					// Inject Src Box Into Empty Space
					break;
				}
				default:
					return false;
			}
			return true;
		}

		bool setBoxArea(int w, int h){
			if(w < 0) w = 0;
			if(h < 0) h = 0;
			if(w == 0 || h == 0){
				this->data.width = 0;
				this->data.height = 0;
				this->data.data_size = 0;
				if(this->data.data != NULL) delete[] this->data.data;
				this->data.data = NULL;
				return false;
			}
			
			this->data.width = w;
			this->data.height = h;
			this->data.data_size = w * h;
			if(this->data.data != NULL) delete[] this->data.data;
			this->data.data = new (std::nothrow) wchar_t[this->data.data_size];
			if(this->data.data == NULL){
				return false;
			}
			for(int i=0; i<this->data.data_size; i++) this->data.data[i] = 0x00;

			this->data.pos_corner_top_left = 0;
			this->data.pos_corner_top_right = this->data.width-1;
			this->data.pos_corner_bottom_left = this->data.data_size-this->data.width;
			this->data.pos_corner_bottom_right = this->data.data_size-1;

			return true;
		}
		
		void printBox(void){
                        if(this->data.data == NULL || this->data.data_size <= 0) return;
                        for(int i=0; i<this->data.data_size; i++){
                                wprintf(L"%lc", this->data.data[i]);
                        }
                }
};
