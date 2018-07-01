package com.epicgames.ue4;

import com.DanGames.GearVRGame.OBBDownloaderService;
import com.DanGames.GearVRGame.DownloaderActivity;


public class DownloadShim
{
	public static OBBDownloaderService DownloaderService;
	public static DownloaderActivity DownloadActivity;
	public static Class<DownloaderActivity> GetDownloaderType() { return DownloaderActivity.class; }
}

