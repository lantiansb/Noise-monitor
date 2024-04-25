var map;

$(function() {
	map = new BMap.Map("container");      						// 设置底图
	map.centerAndZoom(new BMap.Point(113.27, 23.12), 13);    	// 初始化地图,设置中心点坐标和地图级别。
	
	//map.addControl(new BMap.MapTypeControl());
	map.addControl(new BMap.NavigationControl());
	map.enableScrollWheelZoom();                  // 启用滚轮放大缩小。
	map.enableKeyboard();                         // 启用键盘操作。
	
	var point = new BMap.Point(113.27, 23.12);    					// 创建点坐标
	var marker = new BMap.Marker(new BMap.Point(113.27, 23.12)); 	// 创建点
	map.addOverlay(marker);            								// 增加点
	//marker.setAnimation(BMAP_ANIMATION_BOUNCE);	//标点跳动提示功能
	var opts = {
		width: 200,     	// 信息窗口宽度
		height: 50,     	// 信息窗口高度
		title: "广州市", 	// 信息窗口标题
	}
	var infoWindow = new BMap.InfoWindow("广州市市中心", opts);  // 创建信息窗口对象 
	marker.addEventListener("click", function () {
		map.openInfoWindow(infoWindow, point); //开启信息窗口
	});
});


// 标记下位机所在位置
function addFlag(longtitude, lantitide, device_id)
{
	var point = new BMap.Point(longtitude, lantitide);    					// 创建点坐标
	var marker = new BMap.Marker(new BMap.Point(longtitude, lantitide)); 	// 创建点
	map.addOverlay(marker);         										// 增加点
	var opts = {
		width: 200,     							// 信息窗口宽度
		height: 50,     							// 信息窗口高度
		title: '设备id'+(device_id.toString()), 	// 信息窗口标题
	}
	var infoWindow = new BMap.InfoWindow(			// 创建信息窗口对象 
		'位于东经:'+(longtitude.toString())+', 北纬:'+(lantitide.toString()), 
		opts);  
	marker.addEventListener("click", function () {
		map.openInfoWindow(infoWindow, point); //开启信息窗口
	});
}	
