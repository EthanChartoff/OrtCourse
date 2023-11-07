import java.util.Objects;

public class Team {
    private String name;
    private String status;

    public Team(String name, String status) {
        this.name = name;
        this.status = status;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Team team = (Team) o;
        return Objects.equals(name, team.name) && Objects.equals(status, team.status);
    }

    @Override
    public int hashCode() {
        return Objects.hash(name, status);
    }
}
