enum Actions {
  Investigate,
  Sing,
  Nap,
  Spin,
  AttentionSeeking,
  SelfHate,
  Anger,
  Curious
};

#define IDNAME(name) #name
const char* actionNames[] = {
  IDNAME(Investigate),
  IDNAME(Sing),
  IDNAME(Nap),
  IDNAME(Spin),
  IDNAME(AttentionSeeking),
  IDNAME(SelfHate),
  IDNAME(Anger),
  IDNAME(Curious),
};
