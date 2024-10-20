#include "./include/agilor.h"
#include "./include/c_wrapper.h"
#include <stdbool.h>
#include<stdio.h>
#include<stdint.h>


////////////////////////////////////////////////////////////////////////
/////////////////////////// Agilor Connect C API ///////////////////////////
//////////////////////////////////////////////////////////////////////////
//
//TODO: agi_startup(uint64_t thread_id, agibool through_firewall)
int32_t c_Agcn_Startup(uint64_t thread_id, agibool through_firewall) {
    int32_t Startup_result = Agcn_Startup(thread_id, through_firewall);
    switch(Startup_result){
        case 0:
            printf("启动成功。\n");
            break;
        case -1:
            printf("启动失败。\n");
            break;
        default:
            printf("未知错误代码：%d\n", Startup_result);
            break;
    }
    return Startup_result;
}

//TODO: agi_connect(uint64_t thread_id, agibool through_firewall)
int32_t c_Agcn_Connect(const char* server, const char* host_addr, const char* username,
        const char* password, uint32_t port)
{
	int32_t connectResult = Agcn_Connect(server, host_addr, username, password, port);
	switch (connectResult) {
		case 0:
		printf("数据库连接成功。\n");
		break;
		case -1:
		printf( "已经处于连接状态。\n");
		break;
		case -2:
		printf("创建连接点失败。\n");
		break;
		case -3:
		printf("连接点状态错误。\n");
		break;
		case -5:
		printf("已经连接到实时数据库。\n");
		break;
		case -6:
		printf( "创建socket失败。\n");
		break;
		case -7:
		case -8:
		printf("网络错误。\n");
		break;
		case -501:
		printf( "用户名和密码错误。\n");
		break;
		default:
		printf("未知错误： %d.\n", connectResult);
		break;
	}

	return connectResult;
	   
}


//TODO: agi_disconnect(uint64_t thread_id, agibool through_firewall)
int32_t c_Agcn_Disconnect(const char* server) {
	int32_t Discon_result = Agcn_Disconnect(server);
	switch(Discon_result){
		case 0:
		printf("从数据库断开成功。\n");
		break;
		case -2:
		printf("移除连接点失败。\n");
		break;
		case -3:
		printf("连接点状态错误。\n");
		break;
		case -4:
		printf("没有连接到实时数据库。\n");	
	       	break;
	}
	return  Discon_result;

}

/**
 * 清理资源（什么时候调用？）
 */
//TODO: agi_cleanup(uint64_t thread_id, agibool through_firewall)
int32_t c_Agcn_Cleanup() {
	int32_t Clearnup_result = Agcn_Cleanup();
	switch(Clearnup_result){
		case 0:
		printf("成功清理资源。\n");
		break;
		case -1:
		printf("清理资源失败。\n");
		break;	
	}
	return Clearnup_result;

}

//TODO: bool agi_server_info(int32_t* server_id, agilor_serverinfo_t* server_info)
bool c_Agcn_ServerInfo(int32_t* server_id, agilor_serverinfo_t* server_info) {
	
	bool ServerInfo_result = Agcn_ServerInfo(server_id, server_info);
	if(ServerInfo_result ){
		printf("查询实时数据库信息成功。\n");
	}else{
		printf("查询实时数据库信息错误。\n");
	}
	return ServerInfo_result;
}

/////////////////////////////////////////////////
///////////////////订阅/////////////////////////

//TODO: int32_t agi_subscribe(const char* server, const char* tags, int32_t count)
int32_t c_Agda_Subscribe(const char* server, const char* tags, int32_t count) {

    int32_t result = Agda_Subscribe(server, tags, count);
    switch(result) {
        case -3:
            printf("连接点状态错误\n");
            break;
        case -4:
            printf("没有连接到实时数据库\n");
            break;
        case -201:
            printf("发送请求失败\n");
            break;
        case -211:
            printf("等待超时\n");
            break;
        case -101:
            printf("标签tag错误\n");
            break;
        case -110:
            printf("订阅测点数量超过了接口单次订阅数量限制\n");
            break;
        case -111:
            printf("订阅测点数量超过了实时数据库单次订阅数量的限制\n");
            break;
        case -112:
            printf("订阅测点数量超过了实时数据库剩余订阅数量的限制\n");
            break;
        case -502:
            printf("没有查看测点的权限\n");
            break;
        case -506:
            printf("没有订阅测点的权限\n");
            break;
        default:
            if (result > 0) {
                printf("成功，成功订阅的测点数量: %d\n", result);
            } else {
                printf("未知错误 %d.\n", result);
            }
            break;
    }

    return result;

}


//TODO: int32_t agi_subscribe(const char* server, const char* tags, int32_t count)
int32_t c_Agda_Unsubscribe(const char* server, const char* tags, int32_t count) {
    int32_t result = Agda_Unsubscribe(server, tags, count);
    switch(result) {
        case -3:
            printf("连接点状态错误\n");
            break;
        case -4:
            printf("没有连接到实时数据库\n");
            break;
        case -201:
            printf("发送请求失败\n");
            break;
        case -211:
            printf("等待超时\n");
            break;
        case -101:
            printf("标签tag错误\n");
            break;
        default:
            if (result > 0) {
                printf("成功，发送给实时数据库的合法tag的数量:%d\n", result);
            } else {
                printf("未知错误 %d.\n", result);
            }
            break;
    }
    return result;
}


//TODO: int32_t agi_unsubscribe_all(const char* server)
int32_t c_Agda_UnsubscribeAll(const char* server) {
    int32_t result = Agda_UnsubscribeAll(server);
    switch(result) {
        case -3:
            printf("连接点状态错误\n");
            break;
        case -4:
            printf("没有连接到实时数据库\n");
            break;
        case -201:
            printf("发送请求失败\n");
            break;
        case -211:
            printf("等待超时\n");
            break;	
	default:
	 if (result > 0) {		
	  printf("成功，实时数据库成功取消订阅的测点数量:%d\n", result);
	} else {
	 printf("未知错误 %d.\n", result);
	 }
	break;
    }
    return result;
}


//TODO: agirecordset agi_get_subscribe_value(const char* server, const char* tag)
agibool c_Agda_GetSubscribeValue(char* server, char* tag, agilor_value_t* value) {
    agibool result = Agda_GetSubscribeValue(server, tag, value);
    if (result == true) {
        printf("枚举订阅测点实时数据成功\n");
    } else {
        printf("枚举订阅测点实时数据失败\n");
    }
    return result;
}

/**
 * 什么时候调用？
 */
//removed从该记录集中取出所有数据后，是否清除该记录集
//TODO: agibool agi_get_subscribe_next(agirecordset recordset, char* tag, agilor_value_t* value, agibool removed)
agibool c_Agda_NextValue(agirecordset recordset, char* tag, agilor_value_t* value, agibool removed) {
    agibool result = Agda_NextValue(recordset, tag, value, removed);
    if (result == true) {
        printf("成功枚举历史数据\n");
    } else {
        printf("枚举失败\n");
    }
    return result;
}

/**
 这是点数据历史查询？
 */
//TODO: agirecordset agi_get_timedvalue(const char* server, const char* tag, int64_t start_time, int64_t end_time, int64_t step)
agirecordset c_Agda_TimedValue(const char* server, const char* tag, int64_t start_time, int64_t end_time, int64_t step)
{
    agirecordset result = Agda_TimedValue(server, tag, start_time, end_time, step);
    
    if (result > 0) {
        printf("查询成功，记录集 ID: %lld\n", result);
    } else {
        switch (result) {
            case -3:
                printf("连接状态错误。\n");
                break;
            case -4:
                printf("尚未连接实时数据库。\n");
                break;
            case -201:
                printf("发送请求失败。\n");
                break;
            case -211:
                printf("等待超时。\n");
                break;
            case -101:
                printf("标签错误。\n");
                break;
            case -502:
                printf("没有查看测点的权限。\n");
                break;
            case -505:
                printf("没有查看测点历史数据的权限。\n");
                break;
            default:
                printf("未知错误：%lld。\n", result);
                break;
        }
    }

    return result;
}

/**
 * 
 */
//TODO: 重复声明
agirecordset c_Agda_TimedValues(const char* server, const char* tags, int32_t count, int64_t start_time, int64_t end_time, int64_t step)
{
    agirecordset result = Agda_TimedValues(server, tags, count, start_time, end_time, step);
    
    if (result > 0) {
        printf("查询成功，记录集 ID: %lld\n", result);
    } else {
        switch (result) {
            case -3:
                printf("连接点状态错误。\n");
                break;
            case -4:
                printf("尚未连接到实时数据库。\n");
                break;
            case -201:
                printf("发送请求失败。\n");
                break;
            case -211:
                printf("等待超时。\n");
                break;
            case -101:
                printf("标签tag错误。\n");
                break;
            case -502:
                printf("存在测点没有查看该测点的权限。\n");
                break;
            case -505:
                printf("对于所有测点都没有权限查看历史数据。\n");
                break;
            default:
                printf("未知错误：%lld。\n", result);
                break;
        }
    }

    return result;
}

//////////////////////////////////////////////
////////Agilor Point Function ////////////////
//////////////////////////////////////////////

//TODO: int32_t agi_pt_add(const char* server, const agilor_point_t point, agibool overwrite)
int32_t c_Agpt_AddPoint(const char* server, const agilor_point_t point,agibool overwrite) {
    int32_t AddPoint_result = Agpt_AddPoint(server, point, overwrite);
    switch(AddPoint_result){
        case 0:
            printf("成功添加点。\n");
            break;
        case -3:
            printf("连接点状态错误。\n");
            break;
        case -4:
            printf("未连接到实时数据库。\n");
            break;
        case -201:
            printf("发送请求失败。\n");
            break;
        case -211:
            printf("等待超时。\n");
            break;
        case -503:
            printf("无权限修改点。\n");
            break;
        default:
            if (AddPoint_result < 0)
                printf("服务端错误。\n");
            else
                printf("未知错误：%d\n", AddPoint_result);
            break;
    }
    return AddPoint_result;
}

//TODO: int32_t agi_rm_pt(const char* server, int32 point_id)
int32_t c_Agpt_RemovePoint(const char* server, int32 point_id) {
    int32_t RemovePoint_result = Agpt_RemovePoint(server, point_id);
    switch(RemovePoint_result){
        case 0:
            printf("成功移除点。\n");
            break;
        case -3:
            printf("连接点状态出错。\n");
            break;
        case -4:
            printf("未连接到实时数据库。\n");
            break;
        case -201:
            printf("发送请求失败。\n");
            break;
        case -211:
            printf("等待超时。\n");
            break;
        case -503:
            printf("无权限修改点。\n");
            break;
        default:
            printf("未知错误：%d\n", RemovePoint_result);
            break;
    }
    return RemovePoint_result;
}

    agirecordset c_Agpt_DeviceInfo(const char* server) {
         agirecordset DeviceInfo_result = Agpt_DeviceInfo(server);
         agirecordset recordset = -1; // 防止出错时该值无结果
         if(DeviceInfo_result > 0){
            printf("设备信息获取成功，记录集ID：%lld\n", DeviceInfo_result);
            recordset = DeviceInfo_result;
    } else {
        switch(DeviceInfo_result){
            case -3:
                printf("连接点状态错误。\n");
                break;
            case -4:
                printf("未连接到实时数据库。\n");
                break;
            case -201:
                printf("发送请求失败。\n");
                break;
            case -211:
                printf("等待超时。\n");
                break;
            case -502:
                printf("无权限查看点。\n");
                break;
            default:
                printf("未知错误：%lld\n",DeviceInfo_result);
                break;
        }
    }
    return recordset;
}

//TODO: agibool agi_query_dev_next(agirecordset recordset, int32_t* device_id, agilor_deviceinfo_t* device_info)
agibool c_Agpt_NextDeviceInfo(agirecordset recordset, int32_t* device_id,
                                            agilor_deviceinfo_t* device_info) {
    agibool NextDeviceInfo_result = Agpt_NextDeviceInfo(recordset, device_id, device_info);
    if(NextDeviceInfo_result == agitrue){
        printf("成功获取设备信息。\n");
    } else {
        printf("获取设备信息失败。\n");
    }
    return NextDeviceInfo_result;
}

//TODO: agi_query_pt_by_tag(const char* server, int32_t* point_id, char* tag)
int32_t c_Agpt_Tag(const char* server, int32_t point_id,char* tag) {
    int32_t Tag_result = Agpt_Tag(server, point_id, tag);
    switch (Tag_result) {
        case 0:
            printf("标签查询成功。\n");
            break;
        case -3:
            printf("连接点状态错误。\n");
            break;
        case -4:
            printf("未连接到实时数据库。\n");
            break;
        case -201:
            printf("发送请求失败。\n");
            break;
        case -211:
            printf("等待超时。\n");
            break;
        case -101:
            printf("测点ID不正确。\n");
            break;
        case -502:
            printf("无权查看该点。\n");
            break;
        default:
            printf("未知错误：%d\n", Tag_result);
            break;
    }

    return Tag_result;
}


//TODO: rename int32_t agi_count_pt(cosnt char* server, const char* device_name, int32_t* count)
int32_t c_Agpt_PointCount(const char* server, const char* device_name, int32_t* count) {
    int32_t PointCount_result = Agpt_PointCount(server, device_name, count);
    if (PointCount_result== 0) {
        printf("点计数获取成功，点数：%d\n", *count);
     } else {
        switch (PointCount_result) {
            case -3:
                printf("连接点状态错误。\n");
                break;
            case -4:
                printf("未连接到实时数据库。\n");
                break;
            case -201:
                printf("发送请求失败。\n");
                break;
            case -211:
                printf("等待超时。\n");
                break;
            case -502:
                printf("无权限查看点。\n");
                break;
            case 1019:
                printf("设备不存在。\n");
                break;
            default:
                printf("未知错误：%d\n", PointCount_result );
                break;
        }
    }
    return PointCount_result;
}


//TODO: agirecordset agi_query_pt_by_devname(const char* server, const char* device_name) {
agirecordset c_Agpt_GetPointByDevice(const char* server, const char* device_name) {
    agirecordset recordset =-1;//防止出错时记录集无结果
    agirecordset GetPointByDevice_result = Agpt_GetPointByDevice(server, device_name);
    if (GetPointByDevice_result > 0) {
        recordset =GetPointByDevice_result;
        printf("设备点获取成功，记录集ID：%lld\n", recordset);
    } else {
        switch (GetPointByDevice_result ) {
            case -3:
                printf("连接点状态错误。\n");
                break;
            case -4:
                printf("未连接到实时数据库。\n");
                break;
            case -201:
                printf("发送请求失败。\n");
                break;
            case -211:
                printf("等待超时。\n");
                break;
            case -502:
                printf("无权限查看点。\n");
                break;
            case 1019:
                printf("设备不存在。\n");
                break;
            default:
                printf("未知错误：%lld\n",GetPointByDevice_result);
                break;
        }
    }
    return recordset;
}

//TODO: agibool agi_query_pt_next(agirecordset recordset, int32_t* point_id, char* tag)
agibool c_Agpt_NextPoint(agirecordset recordset, int32_t* point_id, char* tag) {
    agibool NextPoint_result= Agpt_NextPoint(recordset, point_id, tag);
    if (NextPoint_result == agitrue) {
        printf("成功获取测点标签，测点ID：%d，标签：%s\n", *point_id, tag);
    } else {
        printf("获取测点标签失败。\n");
    }
    return NextPoint_result;
}

//TODO: agibool agi_query_pt(const char* server, const char* tag, agilor_point_t* point)
int32_t c_Agpt_Point(const char* server, const char* tag, agilor_point_t* point) {
    int32_t Point_result = Agpt_Point(server, tag, point);
    if (Point_result == 0) {
        printf("测点信息获取成功。\n");
    } else {
        switch (Point_result) {
            case -3:
                printf("连接点状态错误。\n");
                break;
            case -4:
                printf("未连接到实时数据库。\n");
                break;
            case -201:
                printf("发送请求失败。\n");
                break;
            case -211:
                printf("等待超时。\n");
                break;
            case -101:
                printf("标签tag错误。\n");
                break;
            case -502:
                printf("无权限查看测点。\n");
                break;
            default:
                printf("未知错误：%d\n", Point_result );
                break;
        }
    }
    return Point_result;
}

//TODO: int32_t agi_pt_exist(const char* server, const char* tag)
int32_t c_Agpt_PointExist(const char* server, const char* tag) {
    int32_t PointExist = Agpt_PointExist(server, tag);
    if (PointExist > 0) {
        printf("测点存在，标签ID：%d\n",PointExist);
    } else {
        switch (PointExist ) {
            case -3:
                printf("连接点状态错误。\n");
                break;
            case -4:
                printf("未连接到实时数据库。\n");
                break;
            case -5:
                printf("测点不存在。\n");
                break;
            case -201:
                printf("发送请求失败。\n");
                break;
            case -211:
                printf("等待超时。\n");
                break;
            case -502:
                printf("无权限查看测点。\n");
                break;
            default:
                printf("未知错误：%d\n", PointExist );
                break;
        }
    }
    return PointExist;
}