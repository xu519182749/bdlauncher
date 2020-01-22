// Generated by scripts/generate_command_definition.py

#include "tp.command.h"

template <> class BDL::CustomCommand::CommandParameterProxy<TPCMD> {
  TPCMD value;

public:
  static auto fetch_tid() { return type_id<CommandRegistry, TPCMD>(); }
  static constexpr auto parser    = &CommandRegistry::fake_parse;
  static constexpr auto type      = CommandParameterDataType::NORMAL;
  static constexpr auto enum_name = "TPCMD";

  operator TPCMD() const noexcept { return value; }
};

struct TPACommand_0 : Command {
  CommandParameterProxy<TPCMD> mode;
  CommandParameterProxy<std::string> target;
  virtual void execute(CommandOrigin const &origin, CommandOutput &output) override {
    TPACommand context{origin, output};
    context.invoke(mode, target);
  }
};

void register_commands() {
  auto &instance = CustomCommandRegistry::getInstance();
  {
    auto &item = instance.registerEnum<TPCMD>();
    item.addValue("cancel", TPCMD::cancel);
    item.addValue("ac", TPCMD::ac);
    item.addValue("de", TPCMD::de);
    item.addValue("gui", TPCMD::gui);
    item.addValue("f", TPCMD::f);
    item.addValue("t", TPCMD::t);
  }
  {
    auto &cmd = instance.registerCommand<TPACommand>();
    {
      auto &ovl = cmd.registerOverload<TPACommand_0>();
      ovl.addParameter<TPCMD>("mode", false, offsetof(TPACommand_0, mode));
      ovl.addParameter<std::string>("target", true, offsetof(TPACommand_0, target));
    }
  }
}