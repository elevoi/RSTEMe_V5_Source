#ifndef ETYPEDEF_H
#define ETYPEDEF_H
#include <QVariant>

class ETypeDef
{
public:
    ETypeDef();

    enum StateChange{
        CONNECTION,
        LIST_DEVICE,
        LIST_ONLINE
    };
    enum ESensorTool{
        ESEN_TEMPERATURE    = 0x101,
        ESEN_HUMIDITY       = 0x102,
        ESEN_FORCE          = 0x103,
        ESEN_PRESSURE       = 0x104,
        ESEN_SOUND          = 0x105,
        ESEN_PH             = 0x106,
        ESEN_DO             = 0x107,
        ESEN_OXY            = 0x108,
        ESEN_SAS            = 0x109,
        ESEN_CO2            = 0x10A,
        ESEN_CON            = 0x10B,
        ESEN_VOLT           = 0x10C,
        ESEN_AMPE           = 0x10D,
        ESEN_DISTANCE       = 0x10E,
        ESEN_MAGNETIC       = 0x10F,
        ESEN_LIGHT          = 0x110,
        ESEN_MOISTURE       = 0x111,
        ESEN_TEMP_K         = 0x112,
        ESEN_MOVE           = 0x113,
        ESEN_HEART          = 0x114
    };
    /*
        "Không biết",
        "Cài đặt thiết bị",
        "Cài đặt tài khoản",
        "Cài đặt mã thiết bị",
        "Kiểm tra kết nối",
        "Tìm thiết bị mới",
        "Cài đặt kết nối",
        "Thêm thiết bị",
        "Hiển thị số",
        "Hiển thị kim",
        "Đồ thị đơn",
        "Đồ thị kết hợp",
        "Đồ thị so sánh",
        "Bảng hiển thị số",
        "Hiệu chuẩn",
        "Danh sách thiết bị"
     */

    struct TypeDevice{
        int id=0;
        QString name = 0;
    };

    inline QList<TypeDevice> listGroupDevice() const {return m_listGroupDevice;}
    inline QList<TypeDevice> listTypeSensor() const {return m_listTypeSensor;}
    inline QList<TypeDevice> listTypeModule() const {return m_listTypeModule;}
    inline QList<TypeDevice> listTypeSystem() const {return m_listTypeSystem;}
    inline QList<TypeDevice> listTypeSoftware() const {return m_listTypeSoftware;}
    inline QList<TypeDevice> listTypeTool() const {return m_listTypeTool;}
private:
    QList<TypeDevice> const     m_listGroupDevice={
        {0x00,"Phần mềm"},
        {0x01,"Cảm biến"},
        {0x02,"Mô-đun thực hành"},
        {0x03,"Mô hình thí nghiệm"},
        {0x04,"Công cụ thực hành"}
    };
    QList<TypeDevice>  const    m_listTypeSensor={
        {0x01,"Cảm biến nhiệt độ"},
        {0x02,"Cảm biến độ ẩm"},
        {0x03,"Cảm biến lực"},
        {0x04,"Cảm biến áp suất"},
        {0x05,"Cảm biến âm thanh"},
        {0x06,"Cảm biến pH"},
        {0x07,"Cảm biến DO"},
        {0x08,"Cảm biến O2"},
        {0x09,"Cảm biến độ mặn"},
        {0x10,"Cảm biến CO2"},
        {0x11,"Cảm biến độ đục"},
        {0x12,"Cảm biến ánh sáng"},
        {0x15,"Cảm biến độ dẫn điện"},
        {0x21,"Cảm biến khoảng cách"},
        {0x23,"Cảm biến chuyển động"},
        {0x50,"Cảm biến điện thế"},
        {0x51,"Cảm biến dòng điện"},
        {0x52,"Cảm biến từ trường"},
        {0x70,"Cảm biến độ ẩm đất"},
        {0x90,"Cảm biến nhịp tim"}
    };
    QList<TypeDevice> const m_listTypeModule={
        {0x01,"Mô-đun đo lực"},
        {0x02,"Mô-đun đo dao động lò xo"},
        {0x03,"Mô-đun thực hành xe va chạm"}
        };
    QList<TypeDevice> const m_listTypeSystem={
        {0x01,"Mô hình nhà thông minh"},
        {0x02,"Mô hình vi khí hậu"},
        {0x03,"Mô hình cánh tay rô-bốt"},
        {0x04,"Mô hình xe rô-bốt"},
        {0x21,"Mô hình khí canh"}
    };
    QList<TypeDevice> const m_listTypeSoftware={
        {0x01,"Cài đặt thiết bị"},
        {0x02,"Tài khoản"},
        {0x03,"Mã thiết bị"},
        {0x04,"Kiểm tra kết nối"},
        {0x05,"Tìm thiết bị mới"},
        {0x06,"Cài đặt kết nối"},
        {0x07,"Thêm thiết bị"},
        {0x08,"Danh sách thiết bị"},
        {0x09,"Hiệu chuẩn"}
    };
    QList<TypeDevice> const m_listTypeTool={
        //display
        {0x01,"Hiển thị số"},
        {0x02,"Bảng hiển thị số"},
        {0x03,"Hiển thị kim"},
        {0x04,"Đồ thị"},
        {0x05,"Máy hiện sóng"},
        //control
        {0x51,"Cấu hình thiết bị"},
        //Practice
        {0x61,"Thực hành cơ bản"},
        {0x62,"Thực hành sóng âm"}
    };
};

#endif // ETYPEDEF_H
