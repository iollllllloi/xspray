//
//  AppDescription.h
//  Xspray
//
//  Created by Sébastien Métrot on 7/1/13.
//
//

#pragma once

class AppDescription : public nuiObject
{
public:
  static int AddApp(const nglPath& rPath);
  static int GetAppCount();
  static AppDescription* GetApp(int index);
  static void RemoveApp(int index);

  bool IsValid() const;

  const nglString& GetName() const;
  const nglPath& GetLocalPath() const;
  const nglPath& GetRemotePath() const;

  const std::vector<nglString>& GetArchitectures() const;
  const std::vector<nglString>& GetVendors() const;
  const std::vector<nglString>& GetTargetOSes() const;
  const nglString& GetArchitecture() const;
  const nglString& GetVendor() const;
  const nglString& GetTargetOS() const;
  nuiTexture* GetIcon() const;
  const nglString& GetDevice();

  const std::vector<nglString>& GetArguments() const;
  const std::map<nglString, nglString>& GetEnvironement() const;

  void DelArgument(int32 index);
  void DelEnvironement(const nglString& rVar);
  void SetArgument(int32 index, const nglString& rString);
  void SetEnvironement(const nglString& rVar, const nglString& rString);
  void AddArgument(const nglString& rString);
  void InsertArgument(int32 index, const nglString& rString);

  nuiSimpleEventSource<0> Changed;

protected:
  AppDescription(const nglPath& rPath);
  virtual ~AppDescription();

  nglString mName;
  nglPath mLocalPath;
  nglPath mRemotePath;

  std::vector<nglString> mArchitectures;
  std::vector<nglString> mVendors;
  std::vector<nglString> mTargetOSes;

  nglString mDevice;
  nglString mArchitecture;
  nglString mVendor;
  nglString mTargetOS;

  std::vector<nglString> mArguments;
  std::map<nglString, nglString> mEnvironement;

  nuiTexture* mpIcon;

  bool LoadBundleIcon(const nglPath& rBundlePath);

  static std::vector<AppDescription*> mApplications;

};

