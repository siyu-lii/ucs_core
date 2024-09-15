package model

import (
	"github.com/lingfliu/ucs_core/conn"
	"github.com/lingfliu/ucs_core/model/gis"
)

const (
	//错误码
	ERR_CODE_OK       = 0 //正常
	ERR_CODE_OVERFLOW = 1 //溢出
	ERR_CODE_LOWPOWER = 2 //低电量
	ERR_CODE_DEAD     = 3 //死机
	ERR_CODE_DRIFT    = 4 //漂移
)

/**
 * 基础物模型
 *  1. 基本属性：id，归属，描述，
 *  2. 连接属性：地址，协议，网关
 *  3. 时空属性
 *  4. 基础属性：在线状态，错误码
 *  5. 设备属性：int，float, bool
 *  6. 数据-事件
 */

type UNode struct {
	Id       int64 //数据库检索用
	ParentId int64
	Mac      string            //可选
	Name     string            //名称
	Desc     string            //概要描述(型号，设备商)
	PropSet  map[string]string //静态属性

	//连接属性
	Addr    string //ip or url
	ConnCfg *conn.ConnCfg
	Url     string //网关连接模式下，该值为内部地址

	//位置信息
	GPos *gis.GPos
	LPos *gis.LPos
	Velo *gis.Velo //速度：x,y,z unit: m/s

	//状态属性
	Online  bool //在线状态
	ErrCode int  //错误码

	NodeSet  map[string]*UNode  //子节点
	PointSet map[string]*UPoint //数据/状态列表
}